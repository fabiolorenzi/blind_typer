#include <iostream>
#include "../headers/Orders.h"

void startScripts() {
    std::cout << std::endl;
    std::cout << "/*------------------*/" << std::endl;
    std::cout << "Welcome to Blind Typer!" << std::endl;
    std::cout << "Developed by F. Lorenzi" << std::endl;
    std::cout << "/*------------------*/" << std::endl;
}

int mainMenu() {
    int decidedPath {-1};

    std::cout << std::endl;
    std::cout << "Please choose what to do:" << std::endl;
    while (decidedPath == -1) {
        std::cout << "[0] Race, [1] Read, [2] Add, [3] Remove, [4] Exit" << std::endl;
        std::cin >> decidedPath;

        if (decidedPath < 0 || decidedPath > 4) {
            decidedPath = -1;
            std::cout << std::endl;
            std::cout << "You have inserted an invalid value!" << std::endl;
            std::cout << "Please decide what to do:" << std::endl;
            std::cout << std::endl;
        };
    };
    return decidedPath;
}