#include <iostream>
#include "headers/Add.h"
#include "headers/Exit.h"
#include "headers/Orders.h"
#include "headers/Race.h"
#include "headers/Read.h"
#include "headers/Remove.h"

int main() {
    int path {};
    startScripts();
    while (path != 4) {
        path = mainMenu();
        switch(path) {
            case 0:
                raceScripts();
                break;
            case 1:
                readScripts();
                break;
            case 2:
                addScripts();
                break;
            case 3:
                removeScripts();
                break;
        };
    };
    exitProgram();

    return 0;
}