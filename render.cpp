#include <iostream>
#include "global_constants.h"
#include "render.h"

void renderMainMenu() {
    char choice;
    std::cout << "\x1B[2J\x1B[H";
    while (true) {
        std::cout << "HANGMAN" << "\n\n";
        for (int i = 0; i < 3; ++i) {
            std::cout << i + 1 << ". " << mainMenuOptions[i] << " - " << mainMenuOptions[i][0] << '\n';
        }
        std::cout << '\n' << "Command: ";
        std::cin >> choice;
        if (choice == 's' || choice == 'S') {
            renderSettingsMenu();
        }
        if (choice == 'q' || choice == 'Q') {
            std::cout << "\x1B[2J\x1B[H";
            break;
        }
    }
}

void renderSettingsMenu() {
    char settingsChoice;
    std::cout << "\x1B[2J\x1B[H";
    for (int i = 0; i < 2; ++i) {
        std::cout << i + 1 << ". " << settingsOptions[i] << " - " << settingsOptions[i][4] << '\n';
    }
    std::cout << '\n' << "Command: ";
    std::cin >> settingsChoice;
}