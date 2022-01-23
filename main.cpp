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
* <file responsible for running the application>
*
*/

#include "render.h"
#include "global_constants.h"

int main() {
    renderMainMenu(defaultLowerLimit, defaultUpperLimit, defaultAttemptCount); //Everything starts with a call to renderMainMenu()

    return 0;
}