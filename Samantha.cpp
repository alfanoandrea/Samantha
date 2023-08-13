#include <iostream>
#include <thread>
#include <filesystem>

class Color {
public:
    static std::string violet;
    static std::string red;
    static std::string cyan;
    static std::string green;
    static std::string yellow;
    static std::string fucsia;
    static std::string gray;
    static std::string reset;
};

std::string Color::violet = "\033[35m";
std::string Color::red = "\u001b[31m";
std::string Color::cyan = "\u001b[36m";
std::string Color::green = "\u001b[32m";
std::string Color::yellow = "\u001b[33m";
std::string Color::fucsia = "\u001b[35;1m";
std::string Color::gray = "\033[90m";
std::string Color::reset = "\u001b[0m";

void logo(bool &first) {
    system("clear");
    std::cout << Color::cyan;
    std::cout << "\n     _________                             __   __            \n";
    if (first) std::this_thread::sleep_for(std::chrono::milliseconds(150));
    std::cout << "    /   _____/____    _____ _____    _____/  |_|  |__ _____   \n";
    if (first) std::this_thread::sleep_for(std::chrono::milliseconds(150));
    std::cout << "    \\_____  \\\\__  \\  /     \\\\__  \\  /    \\   __\\  |  \\\\__  \\ \n";
    if (first) std::this_thread::sleep_for(std::chrono::milliseconds(150));
    std::cout << "    /        \\/ __ \\|  Y Y  \\/ __ \\|   |  \\  | |   Y  \\/ __ \\_ \n";
    if (first) std::this_thread::sleep_for(std::chrono::milliseconds(150));
    std::cout << "   /_______  (____  /__|_|  (____  /___|  /__| |___|  (____  / \n";
    if (first) std::this_thread::sleep_for(std::chrono::milliseconds(150));
    std::cout << "           \\/     \\/      \\/     \\/     \\/          \\/     \\/ \n";
    if (first) std::this_thread::sleep_for(std::chrono::milliseconds(400));
    std::cout << Color::yellow << "\t\t\t\t\t\t\t\x1B[3m by alfanowski\n" << Color::reset;
    if (first) std::this_thread::sleep_for(std::chrono::milliseconds(400));
    first = false;
}

bool conversione(std::string scelta) {
    try {
        std::stoi(scelta);
        return true;
    }
    catch (const std::invalid_argument& e) {
        return false;
    }
}

int intro(bool &first) {
    std::string scelta;
    int sel;
    do {
        logo(first);
        std::cout << Color::red << "\n   X) " << Color::reset << "Exit\t";
        std::cout << Color::green << "   Y) " << Color::reset << "About\n\n";
        std::cout << Color::yellow << "  1) " << Color::reset << "System Info          ";
        std::cout << Color::yellow << "  6) " << Color::reset << "Take Screenshot      \n";
        std::cout << Color::yellow << "  2) " << Color::reset << "Update Packages      \n";
        std::cout << Color::yellow << "  3) " << Color::reset << "Update System        \n";
        std::cout << Color::yellow << "  4) " << Color::reset << "Network Info         \n";
        std::cout << Color::yellow << "  5) " << Color::reset << "Restart Network      \n";
        std::cout << Color::cyan << "\n   >> " << Color::reset;
        std::cin >> scelta;
        if (scelta == "x" or scelta == "X")
            sel = 0;
        else if (scelta == "y" or scelta == "Y")
            sel = -1;
        else {
            if (conversione(scelta)) {
                sel = std::stoi(scelta);
                if (std::to_string(sel) != scelta)
                    sel = 99;
            }
            else
                sel = 99;
        }
    } while (sel < -1 or sel > 6);
    return sel;
}

void about() {
    std::cout << "\n\n" << Color::reset;
    std::cout << Color::green << "\tGithub: " << Color::violet << "https://github.com/alfanoandrea\n\n" << Color::reset;
    std::cout << Color::green << "\tReplit: " << Color::violet << "https://replit.com/@alfanoandrea\n\n" << Color::reset;
    std::cin.ignore();
    std::cin.get();
}

void infoSystem() {
    std::cout << "\n\n" << Color::reset;
    system("neofetch");
    std::cin.ignore();
    std::cin.get();
}

void packageUpdate() {
    std::cout << "\n\n" << Color::reset;
    system("sudo apt-get update");
}

void systemUpdate() {
    std::cout << "\n\n" << Color::reset;
    system("sudo apt-get upgrade");
}

void infoNetwork() {
    std::cout << "\n\n" << Color::reset;
    system("ifconfig");
    std::cin.ignore();
    std::cin.get();
}

void restartNetwork() {
    system("sudo systemctl restart NetworkManager");
}

// ho usato chat-GPT per fare questa funzione poiché non conosco la libreria <iomanip>
std::string getCurrentTimestamp() {
    std::time_t currentTime = std::time(nullptr);
    std::tm* localTime = std::localtime(&currentTime);
    std::stringstream timestamp;
    timestamp << std::put_time(localTime, "%Y-%m-%d_%H-%M-%S");
    return timestamp.str();
}

void screenshot() {
    std::cout << "\n\n" << Color::reset;
    std::string cartella = "./Screenshots";
    if (!std::filesystem::exists(cartella))
        std::filesystem::create_directory(cartella);
    std::string nomeFile = "screenshot_" + getCurrentTimestamp() + ".png";
    std::string percorsoFile = cartella + "/" + nomeFile;
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    //system("sleep 2");
    system(("scrot " + percorsoFile).c_str());
    std::cout << "   Screenshot saved in " << Color::cyan << percorsoFile << Color::reset << "\n\n";
    std::cin.ignore();
    std::cin.get();
}



int main() {
    int a;
    bool first = true;
    do {
        switch(a = intro(first)) {
            case 0:
                break;
            case -1:
                logo(first);
                about();
                break;
            case 1:
                logo(first);
                infoSystem();
                break;
            case 2:
                logo(first);
                packageUpdate();
                break;
            case 3:
                logo(first);
                systemUpdate();
                break;
            case 4:
                logo(first);
                infoNetwork();
                break;
            case 5:
                logo(first);
                restartNetwork();
                break;
            case 6:
                logo(first);
                screenshot();
                break;
        }
    } while (a != 0);
    system("clear");
    return 0;
}
