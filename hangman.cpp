#include <iostream>
#include "global_constants.h"
#include "hangman.h"

int lowerLimit = defaultLowerLimit, upperLimit = defaultUpperLimit, attempts = defaultAttemptCount;

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
            break;
        }
        else if (choice == 'q' || choice == 'Q') {
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
    if (settingsChoice == 'l' || settingsChoice == 'L') {
        std::cout << "\x1B[2J\x1B[H";
        std::cout << "Current lower limit is " << lowerLimit << " and the default is " << defaultLowerLimit << "." << '\n';
        std::cout << "Current upper limit is " << upperLimit << " and the default is " << defaultUpperLimit << "." << "\n\n";
        int newLowerLimit, newUpperLimit;
        do {
            std::cout << "Please enter a valid lower limit: ";
            std::cin >> newLowerLimit;
        } while (newLowerLimit < defaultLowerLimit || newLowerLimit > defaultUpperLimit);
        lowerLimit = newLowerLimit;
        do {
            std::cout << "Please enter a valid upper limit: ";
            std::cin >> newUpperLimit;
        } while (newUpperLimit < defaultLowerLimit || newUpperLimit > defaultUpperLimit || newUpperLimit < newLowerLimit);
        upperLimit = newUpperLimit;
    } else if (settingsChoice == 'a' || settingsChoice == 'A') {
        std::cout << "\x1B[2J\x1B[H";
        std::cout << "Current attempt count per round is " << attempts << "." << '\n';
        int newAttemptCount;
        do {
            std::cout << "Please enter a valid attempt count: ";
            std::cin >> newAttemptCount;
        } while (newAttemptCount < 1);
        attempts = newAttemptCount;
    }
    renderMainMenu();
}