#include <iostream>
#include "headers/Exit.h"
#include "headers/Orders.h"
#include "headers/Read.h"

int main() {
    int path {};
    startScripts();
    while (path != 4) {
        path = mainMenu();
        switch(path) {
            case 0:
                std::cout << "Temporary 0" << std::endl;
                break;
            case 1:
                menuScripts();
                break;
            case 2:
                std::cout << "Temporary 2" << std::endl;
                break;
            case 3:
                std::cout << "Temporary 3" << std::endl;
                break;
        };
    };
    exitProgram();

    return 0;
}