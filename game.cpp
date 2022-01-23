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
* <file containing a definition for the function 
* declared in game.h>
*
*/

#include <algorithm>
#include <iostream>
#include <vector>
#include "game.h"
#include "generate.h"
#include "render.h"

void gameSequence(int lowerLimit, int upperLimit, int attempts) {
    std::string word = generateWord(lowerLimit, upperLimit); // Generate a word based on the provided limits
    std::string state(word.length(), '_'); // Initialize state string for tracking the state of the word during the guessing phase 
    std::vector<char> guessedLetters; // Initialize vector which will contain letters that have already been guessed
    char guess; 
    std::cout << "\x1B[2J\x1B[H";
    while (word != state && attempts > 0) { // While the word hasn't been guessed and the user still has attempts left 
        std::cout << "You have " << attempts << (attempts > 1 ? " attempts " : " attempt ") << "left.\n";
        std::cout << "Guess the word: ";
        for (char s : state) {
            std::cout << s << ' ';
        }
        std::cout << '\n';
        std::cin >> guess; // Prompt user for guess
        if (guess >= 'a' && guess <= 'z') { // If the guess is a lowercase letter
            if (std::find(guessedLetters.begin(), guessedLetters.end(), guess) == guessedLetters.end()) { // If the letter hasn't already been guessed 
                if (word.find(guess) < word.length()) { // If the word contains the guessed letter
                    for (int i = 0; i < word.length(); ++i) {
                        if (guess == word[i]) state[i] = guess; // Modify the state to showcase the guessed letter and its whereabouts
                    }
                } else --attempts; // If the word doesn't contain the guessed letter, deduct one attempt from the player
                guessedLetters.push_back(guess); // Add guessed letter to the guessedLetters vector
            } else std::cout << "Letter already guessed.\n"; // If the letter has already been guessed, output a warning
        } else std::cout << "Invalid symbol.\n"; // If the guess is a symbol other than a lowercase letter, output a warning
    }
    if (word != state) std::cout << "You have no attempts left. The word was " << word << ". "; // If the player hasn't guessed the word
    else std::cout << "Congratulations! You guessed the word " << word << ". "; // If the player has guessed the word
    std::cout << "Press Enter to return to the main menu."; 
    std::cin.ignore();
    std::cin.get(); // Pause program so the player can review his performance, resume on Enter keypress 
    renderMainMenu(); // Render the main menu after the game is finished
}