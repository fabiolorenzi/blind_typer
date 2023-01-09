#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "../headers/Read.h"
#include "../headers/Sentence.h"
#include "../headers/User.h"

int menuRead() {
    int decidedPath {-1};
    std::cout << std::endl;
    std::cout << "Please choose what to do:" << std::endl;
    while (decidedPath == -1) {
        std::cout << "[0] Read Sentences, [1] Read User Data, [2] Return Back" << std::endl;
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

void returnBack() {
    std::cout << std::endl;
    std::cout << "/*----------------------*/" << std::endl;
    std::cout << "Welcome back to the main menu" << std::endl;
    std::cout << "/*----------------------*/" << std::endl;
}

void readSentences() {
    std::cout << std::endl;
    std::string sentencesPath = "data/sentences.txt";
    std::ifstream allSentences;
    allSentences.open(sentencesPath);

    if (allSentences.fail()) {
        std::cerr << "Error: unable to open the file" << std::endl;
    };

    while (allSentences.peek() != EOF) {
        std::string line;
        getline(allSentences, line, '*');

        // Below here we are working on the single line
        std::istringstream ss(line);
        std::string part;
        std::vector<std::string> lineData;
        while (std::getline(ss, part, '|')) {
            lineData.push_back(part);
        };
        Sentence sentence = Sentence(std::stoi(lineData[0]), lineData[1], lineData[2], lineData[3]);

        std::cout << "ID: " << sentence.id << std::endl;
        std::cout << "Created by: " << sentence.created_by << std::endl;
        std::cout << "From: " << sentence.from << std::endl;
        std::cout << "Text: " << sentence.text << std::endl;
        std::cout << std::endl;
    };
    allSentences.close();
}

void readUser() {
    std::cout << std::endl;
    std::string userPath = "data/user.txt";
    std::ifstream userData;
    userData.open(userPath);

    if (userData.fail()) {
        std::cerr << "Error: unable to open the file" << std::endl;
    };

    std::vector<int> tempValues;
    std::string temp;
    while (std::getline(userData, temp, '|')) {
        tempValues.push_back(std::stoi(temp));
    };
    User user = User(tempValues[0], tempValues[1], tempValues[2], tempValues[3], tempValues[4]);

    std::cout << "ID: " << user.id << std::endl;
    std::cout << "Min speed: " << user.minSpeed << std::endl;
    std::cout << "Max speed: " << user.maxSpeed << std::endl;
    std::cout << "Aver speed: " << user.averageSpeed << std::endl;
    std::cout << "Sessions: " << user.sessionsFinished << std::endl;
    std::cout << std::endl;

    userData.close();
}

int readScripts() {
    std::cout << std::endl;
    std::cout << "/*------------------*/" << std::endl;
    std::cout << "Read Menu" << std::endl;
    std::cout << "/*------------------*/" << std::endl;
    int path {};
    while (path != 2) {
        path = menuRead();
        switch(path) {
            case 0:
                readSentences();
                break;
            case 1:
                readUser();
                break;
        };
    };
    returnBack();

    return 0;
}