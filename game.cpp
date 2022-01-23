#include <algorithm>
#include <iostream>
#include <vector>
#include "game.h"
#include "generate.h"
#include "render.h"

void gameSequence(int lowerLimit, int upperLimit, int attempts) {
    std::string word = generateWord(lowerLimit, upperLimit);
    std::string state(word.length(), '_');
    std::vector<char> guessedLetters;
    char guess;
    std::cout << "\x1B[2J\x1B[H";
    while (word != state && attempts > 0) {
        std::cout << "You have " << attempts << (attempts > 1 ? " attempts " : " attempt ") << "left.\n";
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
                guessedLetters.push_back(guess);
            } else std::cout << "Letter already guessed.\n";
        } else std::cout << "Invalid symbol.\n";
    }
    if (word != state) std::cout << "You have no attempts left. The word was " << word << ". ";
    else std::cout << "Congratulations! You guessed the word " << word << ". ";
    std::cout << "Press Enter to return to the main menu.";
    std::cin.ignore();
    std::cin.get();
    renderMainMenu();
}