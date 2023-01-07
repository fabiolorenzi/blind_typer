#include <iostream>
#include <time.h>
#include "../headers/Exit.h"

int exitProgram() {
    time_t start, end;

    std::cout << std::endl;
    std::cout << "See you next time! :)" << std::endl;
    start = time(0);
    while (true) {
        if (time(0) - start == 1) {
            return 0;
        }
    };
}