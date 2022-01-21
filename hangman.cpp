#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
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
        if (choice == 'p' || choice == 'P') {
            gameSequence(lowerLimit, upperLimit, attempts);
            break;
        }
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

std::string generateWord(int lowerLimit, int upperLimit) {
    std::vector<std::string> options;
    std::fstream dictionaryReader;
    dictionaryReader.open("dictionary.txt", std::fstream::in);
    std::string entry;

    while (getline(dictionaryReader, entry)) {
        if (entry.size() >= lowerLimit && entry.size() <= upperLimit) {
            options.push_back(entry);
        }
    }

    dictionaryReader.close();

    srand(time(NULL));
    return options[rand() % options.size()];    
}

void gameSequence(int lowerLimit, int upperLimit, int attempts) {
    std::string word = generateWord(lowerLimit, upperLimit);
    std::string state(word.length(), '_');
    std::vector<char> guessedLetters;
    char guess;
    std::cout << "\x1B[2J\x1B[H";
    while (word != state && attempts > 0) {
        std::cout << "You have " << attempts << (attempts > 1 ? " attempts " : " attempt ") << "left." << '\n';
        std::cout << "Guess the word: ";
        for (char s : state) {
            std::cout << s << ' ';
        }
        std::cout << '\n';
        std::cin >> guess;
        if (guess >= 'a' && guess <= 'z') {
            if (std::find(guessedLetters.begin(), guessedLetters.end(), guess) == guessedLetters.end()) {
                if (word.find(guess) < word.length()) {
                    for (int i = 0; i < word.length(); ++i) {
                        if (guess == word[i]) state[i] = guess;
                    }
                } else --attempts;
            }
        }
        std::cout << '\n';
    }
    if (word != state) std::cout << "You have no attempts left. The word was " << word << ". ";
    else std::cout << "Congratulations! You guessed the word " << word << ". ";
    std::cout << "Press Enter to return to the main menu.";
    std::cin.ignore();
    std::cin.get();
    renderMainMenu();
}