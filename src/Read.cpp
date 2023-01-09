#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "../headers/Read.h"

int menuRead() {
    int decidedPath {-1};
    std::cout << std::endl;
    std::cout << "Please choose what to do:" << std::endl;
    while (decidedPath == -1) {
        std::cout << "[0] Read Sentences, [1] Read User Data, [2] Return Back" << std::endl;
        std::cin >> decidedPath;

        if (decidedPath < 0 || decidedPath > 2) {
            decidedPath = -1;
            std::cout << std::endl;
            std::cout << "You have inserted an invalid value!" << std::endl;
            std::cout << "Please decide what to do:" << std::endl;
            std::cout << std::endl;
        };
    };
    return decidedPath;
}

void returnBack() {
    std::cout << std::endl;
    std::cout << "/*----------------------*/" << std::endl;
    std::cout << "Welcome back to the main menu" << std::endl;
    std::cout << "/*----------------------*/" << std::endl;
}

void readSentences() {
    std::cout << std::endl;
    std::string sentencesPath = "data/sentences.txt";
    std::ifstream allSentences;
    allSentences.open(sentencesPath);

    if (allSentences.fail()) {
        std::cerr << "Error: unable to open the file" << std::endl;
    };

    while (allSentences.peek() != EOF) {
        std::string line;
        getline(allSentences, line, '*');

        // Below here we are working on the single line
        std::istringstream ss(line);
        std::string part;
        std::vector<std::string> lineData;
        while (std::getline(ss, part, '|')) {
            lineData.push_back(part);
        };

        std::cout << "Number: " << lineData[0] << std::endl;
        std::cout << "Created by: " << lineData[1] << std::endl;
        std::cout << "Text: " << lineData[2] << std::endl;
        std::cout << std::endl;
    };
    allSentences.close();
}

int menuScripts() {
    std::cout << std::endl;
    std::cout << "/*------------------*/" << std::endl;
    std::cout << "Read Menu" << std::endl;
    std::cout << "/*------------------*/" << std::endl;
    int path {};
    while (path != 2) {
        path = menuRead();
        switch(path) {
            case 0:
                readSentences();
                break;
            case 1:
                std::cout << "Temporary Read 1" << std::endl;
                break;
        };
    };
    returnBack();

    return 0;
}