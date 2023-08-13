Simple Command-Line Utility

This is a simple command-line utility written in C++ that provides various functionalities related to system management and information retrieval. The utility presents a menu-driven interface with different options that the user can choose from.

Features

- Display System Information: Show system details using the 'neofetch' command.
- Update Packages: Update the package list using the 'sudo apt-get update' command.
- Update System: Upgrade the system packages using the 'sudo apt-get upgrade' command.
- Display Network Information: Show network interface details using the 'ifconfig' command.
- Restart Network: Restart the NetworkManager service using the 'sudo systemctl restart NetworkManager' command.
- Take Screenshot: Capture a screenshot and save it to a specified directory.

Getting Started

Prerequisites

Before you begin, make sure you have the following:

- C++ compiler (GCC recommended)
- 'neofetch' command (for displaying system information)
- 'sudo' privileges (for executing system-related commands)

Installation

1. Clone the repository:
   git clone https://github.com/alfanoandrea/Samantha.git

2. Navigate to the repository directory:
   cd Samantha

3. Run the setup script to install required packages:
   sudo bash setup.sh

Usage

1. Run the start script to execute the program:
   bash start.sh

2. Choose from the menu options to interact with the program.

Contributors

- alfanowski (https://github.com/alfanoandrea) - Creator of the program
