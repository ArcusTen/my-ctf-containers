#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string command;
    while (true) {
        std::cout << ">> ";
        std::getline(std::cin, command);

        // Converting command to uppercase
        std::transform(command.begin(), command.end(), command.begin(), ::toupper);

        // If the user wants to exit, break the loop
        if (command == "EXIT") {
            break;
        }

        // Executing the provided command in bash
        std::string bashCommand = "bash -c \"" + command + "\"";
        system(bashCommand.c_str());
    }

    std::cout << "\nQuitting too soon??\nGoodbye :(\n\n";
    return 0;
}
