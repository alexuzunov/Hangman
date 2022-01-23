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
* declared in generate.h>
*
*/

#include <fstream>
#include <vector>
#include "generate.h"

std::string generateWord(int lowerLimit, int upperLimit) {
    std::vector<std::string> options; // Declare vector which will contain the available options based on the provided parameters
    std::fstream dictionaryReader;
    dictionaryReader.open("dictionary.txt", std::fstream::in); // Open dictionary file for reading
    std::string entry;

    while (getline(dictionaryReader, entry)) { //Read line by line
        if (entry.size() >= lowerLimit && entry.size() <= upperLimit) {
            options.push_back(entry); // If the word satisfies the provided limitations, add it to the vector 
        }
    }

    dictionaryReader.close(); // Close dictionary

    srand(time(NULL)); // Use the current time as seed for the pseudo-random number generator used by rand()
    return options[rand() % options.size()]; // Return a random word from the options vector by generating a random index with the mod operator   
}