/**
*  
* Solution to course project #14
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Alex Uzunov
* @idnumber 7MI0600096
* @compiler GCC
* @sourcecontrol https://github.com/alexuzunov/Hangman
*
* <file containing definitions for the functions declared in render.h>
*
*/

#include <iostream>
#include "game.h"
#include "global_constants.h"
#include "render.h"

void renderMainMenu(int lowerLimit, int upperLimit, int attempts) {
    char choice;
    std::cout << "\x1B[2J\x1B[H"; // ANSI escape sequence - clears the screen and returns the cursor to the home position (top left)
    while (true) {
        std::cout << "HANGMAN" << "\n\n";
        for (int i = 0; i < 3; ++i) {
            std::cout << i + 1 << ". " << mainMenuOptions[i] << " - " << mainMenuOptions[i][0] << '\n';
        }
        std::cout << '\n' << "Command: ";
        std::cin >> choice;
        if (choice == 'P') { // Corresponds to the "Play" option
            gameSequence(lowerLimit, upperLimit, attempts); // Initiate game sequence
            break;
        }
        else if (choice == 'S') { // Corresponds to the "Settings" option
            renderSettingsMenu(lowerLimit, upperLimit, attempts); // Render settings menu
            break; // Avoid an abundance of running instances which may make the interface uncomfortable to work with
        }
        else if (choice == 'Q') { // Corresponds to the "Quit" option
            std::cout << "\x1B[2J\x1B[H"; // Clear the screen and break the main menu loop, thus exiting the program
            break;
        } else {
            renderMainMenu(lowerLimit, upperLimit, attempts); // Re-render the main menu if the command doesn't correspond to any of the available ones
            break; // Avoid an abundance of running instances which may make the interface uncomfortable to work with
        }
    }
}

void renderSettingsMenu(int lowerLimit, int upperLimit, int attempts) {
    int newLowerLimit = lowerLimit, newUpperLimit = upperLimit, newAttemptCount = attempts;
    char settingsChoice;
    std::cout << "\x1B[2J\x1B[H";
    while (true) {
        for (int i = 0; i < 2; ++i) {
            std::cout << i + 1 << ". " << settingsOptions[i] << " - " << settingsOptions[i][4] << '\n';
        }
        std::cout << '\n' << "Command: ";
        std::cin >> settingsChoice;
        if (settingsChoice == 'L') { // Corresponds to the "Set Limit (Word Length)" option
            std::cout << "\x1B[2J\x1B[H";
            std::cout << "Current lower limit is " << lowerLimit << " and the default is " << defaultLowerLimit << "." << '\n';
            std::cout << "Current upper limit is " << upperLimit << " and the default is " << defaultUpperLimit << "." << "\n\n";
            do {
                std::cout << "Please enter a valid lower limit: ";
                std::cin >> newLowerLimit;
            } while (newLowerLimit < defaultLowerLimit || newLowerLimit > defaultUpperLimit); // Prompt for input until a valid lower limit is provided 
            do {
                std::cout << "Please enter a valid upper limit: ";
                std::cin >> newUpperLimit;
            } while (newUpperLimit < defaultLowerLimit || newUpperLimit > defaultUpperLimit || newUpperLimit < newLowerLimit); // Prompt for input until a valid upper limit is provided
        } else if (settingsChoice == 'A') { // Corresponds to the "Set Attempt Count" option
            std::cout << "\x1B[2J\x1B[H";
            std::cout << "Current attempt count per round is " << attempts << ".\n";
            do {
                std::cout << "Please enter a valid attempt count: ";
                std::cin >> newAttemptCount;
            } while (newAttemptCount < 1); // Prompt for input until a valid attempt count is provided
        } else {
            renderSettingsMenu(lowerLimit, upperLimit, attempts); // Re-render the settings menu if the command doesn't correspond to any of the available ones 
            break; // Avoid an abundance of running instances which may make the interface uncomfortable to work with
        }
        renderMainMenu(newLowerLimit, newUpperLimit, newAttemptCount); // Re-render the main menu after the respective setting is configured
        break; // Avoid an abundance of running instances which may make the interface uncomfortable to work with
    }
}