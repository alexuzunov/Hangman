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
* responsible for the flow of the Hangman game itself 
* based on word length limits and the amount of attempts the player has>
*
*/

#ifndef GAME_H
#define GAME_H

void gameSequence(int lowerLimit, int upperLimit, int attempts);

#endif