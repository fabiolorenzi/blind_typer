#include <iostream>
#include "headers/Orders.h"

int main() {
    int path {};
    path = mainMenu();
    std::cout << "You have chosen " << path << std::endl;

    return 0;
}