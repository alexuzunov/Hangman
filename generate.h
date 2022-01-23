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
* <header file containing a declaration for a function 
* responsible for generating a word from the dictionary 
* based on word length limits>
*
*/

#ifndef GENERATE_H
#define GENERATE_H

std::string generateWord(int lowerLimit, int upperLimit);

#endif