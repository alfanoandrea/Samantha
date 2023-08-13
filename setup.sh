if [ $UID -ne 0 ]; then
    echo -e "\033[31mThe script must be run as root.\033[0m"
    exit 1
fi

apt-get update
apt-get install neofetch
apt-get install scrot

