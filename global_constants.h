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
* <header file containing a couple of global constants related to the application>
*
*
*/

#ifndef GLOBAL_CONSTANTS_H
#define GLOBAL_CONSTANTS_H

#include <string>

const std::string mainMenuOptions[3] = {"Play", "Settings", "Quit"}; //Main menu options
const std::string settingsOptions[2] = {"Set Limit (Word Length)", "Set Attempt Count"}; //Settings options
const int defaultLowerLimit = 2, defaultUpperLimit = 14; //Default limits (define the availability of words from the dictionary)
const int defaultAttemptCount = 5; //Default attempt count

#endif