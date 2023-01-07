#include <iostream>
#include "headers/Orders.h"
#include "headers/Exit.h"

int main() {
    int path {};
    path = mainMenu();

    if (path == 4) {
        exitProgram();
    };

    return 0;
}