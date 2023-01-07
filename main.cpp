#include <iostream>
#include "headers/Orders.h"
#include "headers/Exit.h"

int main() {
    int path {};
    
    while (path != 4) {
        path = mainMenu();
    };
    exitProgram();

    return 0;
}