#include <iostream>
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
    std::cout << "readSentences" << std::endl;
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