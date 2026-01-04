#include <iostream>
#include <string>
#include <filesystem> // Стандарт C++17 и выше

namespace fs = std::filesystem;

int main() {
    std::string input;

    while (true) {
        // Показываем текущий путь для удобства (как в настоящей консоли)
        std::cout << "\nNow in: " << fs::current_path().string() << "\n";
        std::cout << "> ";
        std::getline(std::cin, input);

        // 1. Команда создания: mkdir [имя]
        if (input.substr(0, 10) == "createDir ") {
            std::string dirName = input.substr(10);
            if (fs::create_directory(dirName)) {
                std::cout << "[System] Directory created: " << dirName << std::endl;
            }
            else {
                std::cout << "[System] Error or folder already exists." << std::endl;
            }
        }

        // 2. Команда перехода: goToDir [имя]
        else if (input.substr(0, 8) == "goToDir ") {
            std::string dirName = input.substr(8);

            if (fs::exists(dirName) && fs::is_directory(dirName)) {
                // МЕНЯЕМ ТЕКУЩУЮ ДИРЕКТОРИЮ ПРИЛОЖЕНИЯ
                fs::current_path(dirName);
                std::cout << "[System] Moved to: " << dirName << std::endl;
            }
            else {
                std::cout << "[System] Error: Directory does not exist!" << std::endl;
            }
        }

        else if (input == "exit") break;
        else {
            std::cout << "[System] Unknown command. Use mkdir or goToDir." << std::endl;
        }
    }

    return 0;
}