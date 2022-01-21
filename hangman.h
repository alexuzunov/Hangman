#ifndef HANGMAN_H
#define HANGMAN_H

void renderMainMenu();
void renderSettingsMenu();
std::string generateWord(int lowerLimit, int upperLimit);
void gameSequence(int lowerLimit, int upperLimit, int attempts);

#endif