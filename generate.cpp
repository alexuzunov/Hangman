#include <fstream>
#include <string>
#include <vector>
#include "generate.h"

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