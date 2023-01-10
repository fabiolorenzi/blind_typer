#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <chrono>
#include <ctime>
#include <Windows.h>
#include "../headers/Race.h"
#include "../headers/Sentence.h"
#include "../headers/User.h"

int menuRace() {
    int decidedPath {-1};
    std::cout << std::endl;
    std::cout << "Please choose what to do:" << std::endl;
    while (decidedPath == -1) {
        std::cout << "[0] Start Game, [1] Return Back" << std::endl;
        std::cin >> decidedPath;

        if (decidedPath < 0 || decidedPath > 1) {
            decidedPath = -1;
            std::cout << std::endl;
            std::cout << "You have inserted an invalid value!" << std::endl;
            std::cout << "Please decide what to do:" << std::endl;
            std::cout << std::endl;
        };
    };
    return decidedPath;
}

std::vector<Sentence> getAllSentences() {
    std::cout << std::endl;
    std::vector<Sentence> result;
    std::string sentencesPath = "data/sentences.txt";
    std::ifstream allSentences;
    allSentences.open(sentencesPath);

    if (allSentences.fail()) {
        std::cerr << "Error: unable to open the file" << std::endl;
    };

    while (allSentences.peek() != EOF) {
        std::string line;
        getline(allSentences, line, '*');
        std::istringstream ss(line);
        std::string part;
        std::vector<std::string> lineData;
        while (std::getline(ss, part, '|')) {
            lineData.push_back(part);
        };
        Sentence sentence = Sentence(std::stoi(lineData[0]), lineData[1], lineData[2], lineData[3]);
        result.push_back(sentence);
    };
    allSentences.close();
    return result;
}

void countdown() {
    int time {5};
    while (time > 0) {
        std::cout << std::to_string(time) + "..." << std::endl;
        Sleep(1000);
        time--;
    };
    std::cout << "Go!!!" << std::endl;
}

void raceSequence() {
    std::vector<Sentence> allSentences = getAllSentences();
    if (allSentences.size() > 0) {

        // The code below is to get a random sentence from the vector
        int randomIndex = rand() % allSentences.size();
        Sentence sentence = allSentences[randomIndex];


        countdown();
        std::cout << sentence.text << std::endl;
        std::cout << std::endl;

        // The code below is for the typing race itself
        auto start = std::chrono::system_clock::now();
        std::string typed;
        std::cin.ignore();
        std::getline(std::cin, typed);
        auto end = std::chrono::system_clock::now();

        if (typed == sentence.text) {
            // The code below is for the result calculations
            std::chrono::duration<double> timeDifference = end - start;
            int timeResult = int(timeDifference.count());
            std::cout << "result" << timeResult << std::endl;
        } else {
            std::cout << "There are some mistakes in the typing :(" << std::endl;
        };
    } else {
        std::cout << "No sentences available." << std::endl;
        std::cout << "Please go in the Add menu and insert at least one" << std::endl;
    };
}

void raceReturnBack() {
    std::cout << std::endl;
    std::cout << "/*----------------------*/" << std::endl;
    std::cout << "Welcome back to the main menu" << std::endl;
    std::cout << "/*----------------------*/" << std::endl;
}

int raceScripts() {
    std::cout << std::endl;
    std::cout << "/*------------------*/" << std::endl;
    std::cout << "Race Menu" << std::endl;
    std::cout << "/*------------------*/" << std::endl;
    int path {};
    while (path != 1) {
        path = menuRace();
        if (path == 0 ) {
            raceSequence();
        };
    };
    raceReturnBack();

    return 0;
}