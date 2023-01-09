#include <iostream>
#include <fstream>
#include <istream>
#include "../headers/Remove.h"
#include "../headers/Sentence.h"

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

void removeReturnBack() {
    std::cout << std::endl;
    std::cout << "/*----------------------*/" << std::endl;
    std::cout << "Welcome back to the main menu" << std::endl;
    std::cout << "/*----------------------*/" << std::endl;
}

void removeSentence() {
    std::cout << "remove sentence" << std::endl;
}

void resetUser() {
    int decision {};
    std::cout << std::endl;
    std::cout << "Are you sure you want to reset the user data?" << std::endl;
    std::cout << "[0] Yes, [1] No" << std::endl;
    std::cin >> decision;
    if (decision == 0) {
        std::ofstream userFile("data/user.txt");
        std::string newUserString = "0|0|0|0|0";
        userFile << newUserString;
        std::cout << std::endl;
        std::cout << "The user has been reset successfully." << std::endl;
    };
}

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