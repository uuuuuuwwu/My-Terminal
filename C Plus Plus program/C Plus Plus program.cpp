#include <iostream>
#include <string>
#include <map>

// Global data

std::string user_name;
int users_password;
std::string current_path;
char home_catalog = '~';
bool admin = false;
std::string admin_symbol = "[$]";

// clear!

void clear() {
    std::cout << "\033[2J\033[H";
}

// "ec" commands

void showVersion() {
    std::cout << "v1.0.0\n";
}

void showName() {
    std::cout << user_name << "\n";
}

void showPath() {
    std::cout << current_path << "\n";
}

// Reference for class "ec"
void ec() {
    std::cout << "\n[CLASS: ec] - Output & Info Commands\n";
    std::cout << "-----------------------------------\n";
    std::cout << "ecVersion : Show software version\n";
    std::cout << "ecName    : Show current user name\n";
    std::cout << "ecPath    : Show virtual directory path\n";
    std::cout << "ec        : Show this help message\n";
    std::cout << "-----------------------------------\n";
}

// I wanna be an admin function

void wannaBeAdmin() {
    int check_password;
    std::cout << "Enter your password: ";
    std::cin >> check_password;

    if (check_password == users_password) {
        admin = true;
        admin_symbol = "[#]";
    }
    else {
        std::cout << "Incorrect password!";
    }
}
// help
void help() {
    std::cout << "Help:\n";
    std::cout << "Enter \"ec\" if you want to see the reference to the class \"ec\"\n";
}

int main() {
    std::cout << "Enter your name: ";
    std::cin >> user_name;

    std::cout << "Enter your password: ";
    std::cin >> users_password;

    current_path = "/home/" + user_name; 

    typedef void (*CommandFunc)();
    std::map<std::string, CommandFunc> commands;

    // class "ec"
    commands["ec"] = ec;
    commands["ecVersion"] = showVersion;
    commands["ecName"] = showName;
    commands["ecPath"] = showPath;
    // clear
    commands["clear"] = clear;
    //wannaBeAdmin
    commands["iWannaBeAnAdmin"] = wannaBeAdmin;
    //help
    commands["help"] = help;

    std::string input;

    while (true) {
        std::cout << user_name << "@Dekstop:Computer@" << home_catalog << admin_symbol << " ";
        std::cin >> input;

        if (input == "exit") break;

        if (commands.count(input)) {
            commands[input]();
        }
        else {
            std::cout << "Error: '" << input << "' is not a recognized command.\n";
        }
    }

    return 0;
}