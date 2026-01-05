#include <iostream>
#include <string>
#include <filesystem> // Ñòàíäàðò C++17 è âûøå

namespace fs = std::filesystem;

int main() {
    std::string input;

    while (true) {
        // Ïîêàçûâàåì òåêóùèé ïóòü äëÿ óäîáñòâà (êàê â íàñòîÿùåé êîíñîëè)
        std::cout << "\nNow in: " << fs::current_path().string() << "\n";
        std::cout << "> ";
        std::getline(std::cin, input);

        // 1. Êîìàíäà ñîçäàíèÿ: mkdir [èìÿ]
        if (input.substr(0, 10) == "createDir ") {
            std::string dirName = input.substr(10);
            if (fs::create_directory(dirName)) {
                std::cout << "[System] Directory created: " << dirName << std::endl;
            }
            else {
                std::cout << "[System] Error or folder already exists." << std::endl;
            }
        }

        // 2. Êîìàíäà ïåðåõîäà: goToDir [èìÿ]
        else if (input.substr(0, 8) == "goToDir ") {
            std::string dirName = input.substr(8);

            if (fs::exists(dirName) && fs::is_directory(dirName)) {
                // ÌÅÍßÅÌ ÒÅÊÓÙÓÞ ÄÈÐÅÊÒÎÐÈÞ ÏÐÈËÎÆÅÍÈß
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
