#include <iostream>
#include <string>
#include <map>
#include <filesystem>
#include <vector>

namespace fs = std::filesystem;

std::string user_name;
int users_password;
fs::path current_path;
char home_catalog = '~';
bool admin = false;
std::string admin_symbol = "[$]";

void clear() {
    std::cout << "\033[2J\033[H";
}

void showVersion() {
    std::cout << "v1.0.0\n";
}

void showName() {
    std::cout << user_name << "\n";
}

void showPath() {
    std::cout << fs::absolute(current_path).string() << "\n";
}

void ec() {
    std::cout << "\n[CLASS: ec] - Output & Info Commands\n";
    std::cout << "-----------------------------------\n";
    std::cout << "ecVersion : Show software version\n";
    std::cout << "ecName    : Show current user name\n";
    std::cout << "ecPath    : Show virtual directory path\n";
    std::cout << "ec        : Show this help message\n";
    std::cout << "-----------------------------------\n";
}

void crt() {
    std::cout << "\n[CLASS: crt] - File System Commands\n";
    std::cout << "-----------------------------------\n";
    std::cout << "crtCreateFolder      : Create a single folder\n";
    std::cout << "crtCreateDirectories : [ADMIN] Create nested folders (path/to/dir)\n";
    std::cout << "crtDeleteFolder      : Delete folder and its content\n";
    std::cout << "cd                   : Change current directory\n";
    std::cout << "crt                  : Show this help message\n";
    std::cout << "-----------------------------------\n";
}

void crtCreateFolder() {
    std::string name;
    std::cin >> name;
    if (fs::create_directory(current_path / name)) {
        std::cout << "Success: Folder created.\n";
    } else {
        std::cout << "Error: Could not create folder.\n";
    }
}

void crtCreateDirectories() {
    if (!admin) {
        std::cout << "Access Denied: Admin privileges required.\n";
        return;
    }
    std::string path_str;
    std::cin >> path_str;
    try {
        if (fs::create_directories(current_path / path_str)) {
            std::cout << "Success: Directory tree created.\n";
        } else {
            std::cout << "Info: Directories already exist.\n";
        }
    } catch (const fs::filesystem_error& e) {
        std::cout << "Error: " << e.what() << "\n";
    }
}

void crtDeleteFolder() {
    std::string name;
    std::cin >> name;
    if (fs::exists(current_path / name)) {
        std::uintmax_t n = fs::remove_all(current_path / name);
        std::cout << "Deleted " << n << " items.\n";
    } else {
        std::cout << "Error: Path not found.\n";
    }
}

void cd() {
    std::string name;
    std::cin >> name;
    fs::path new_path = current_path / name;
    if (fs::exists(new_path) && fs::is_directory(new_path)) {
        current_path = fs::canonical(new_path);
    } else {
        std::cout << "Error: Directory not found.\n";
    }
}

void wannaBeAdmin() {
    int check_password;
    std::cout << "Enter your password: ";
    std::cin >> check_password;
    if (check_password == users_password) {
        admin = true;
        admin_symbol = "[#]";
        std::cout << "Now you are admin.\n";
    } else {
        std::cout << "Incorrect password!\n";
    }
}

void help() {
    std::cout << "\nHelp:\n";
    std::cout << "Enter \"ec\" to see the info about the class ec\n";
    std::cout << "Enter \"crt\" to see the info about the class crt\n";
}

int main() {
    std::cout << "Enter your name: ";
    std::cin >> user_name;
    std::cout << "Enter your password: ";
    std::cin >> users_password;

    current_path = fs::current_path();

    typedef void (*CommandFunc)();
    std::map<std::string, CommandFunc> commands;

    commands["ec"] = ec;
    commands["ecVersion"] = showVersion;
    commands["ecName"] = showName;
    commands["ecPath"] = showPath;
    
    commands["crt"] = crt;
    commands["crtCreateFolder"] = crtCreateFolder;
    commands["crtCreateDirectories"] = crtCreateDirectories;
    commands["crtDeleteFolder"] = crtDeleteFolder;
    commands["cd"] = cd;

    commands["clear"] = clear;
    commands["iWannaBeAnAdmin"] = wannaBeAdmin;
    commands["help"] = help;

    std::string input;
    while (true) {
        std::cout << user_name << "@Dekstop:" << current_path.filename().string() << admin_symbol << " ";
        if (!(std::cin >> input)) break;
        if (input == "exit") break;

        if (commands.count(input)) {
            commands[input]();
        } else {
            std::cout << "Error: '" << input << "' is not a recognized command.\n";
        }
    }

    return 0;
}

