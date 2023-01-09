#include <iostream>
#include "../headers/Remove.h"

int menuRemove() {
    int decidedPath {-1};
    std::cout << std::endl;
    std::cout << "Please choose what to do:" << std::endl;
    while (decidedPath == -1) {
        std::cout << "[0] Remove Sentence, [1] Reset User, [2] Return Back" << std::endl;
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

void removeReturbBack() {
    std::cout << std::endl;
    std::cout << "/*----------------------*/" << std::endl;
    std::cout << "Welcome back to the main menu" << std::endl;
    std::cout << "/*----------------------*/" << std::endl;
}

void removeSentence() {}

void resetUser() {}

int removeScripts() {
    std::cout << std::endl;
    std::cout << "/*------------------*/" << std::endl;
    std::cout << "Remove Menu" << std::endl;
    std::cout << "/*------------------*/" << std::endl;
    int path {};
    while (path != 2) {
        path = menuRemove();
        switch(path) {
            case 0:
                removeSentence();
                break;
            case 1:
                resetUser();
                break;
        };
    };
    removeReturnBack();

    return 0;
}