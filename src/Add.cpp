#include <iostream>
#include <fstream>
#include <istream>
#include <sstream>
#include <vector>
#include "../headers/Add.h"
#include "../headers/Sentence.h"

int menuAdd() {
    int decidedPath {-1};
    std::cout << std::endl;
    std::cout << "Please choose what to do:" << std::endl;
    while (decidedPath == -1) {
        std::cout << "[0] Add Sentences, [1] Return Back" << std::endl;
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

void addReturbBack() {
    std::cout << std::endl;
    std::cout << "/*----------------------*/" << std::endl;
    std::cout << "Welcome back to the main menu" << std::endl;
    std::cout << "/*----------------------*/" << std::endl;
}

int getMaxId() {
    std::string sentencesPath = "data/sentences.txt";
    std::ifstream allSentences;
    allSentences.open(sentencesPath);

    if (allSentences.fail()) {
        return 1;
    };

    int result {};

    while (allSentences.peek() != EOF) {
        std::string line;
        getline(allSentences, line, '*');

        std::istringstream ss(line);
        std::string part;
        std::vector<std::string> lineData;
        while (std::getline(ss, part, '|')) {
            lineData.push_back(part);
        };
        result = std::stoi(lineData[0]);
    };
    allSentences.close();
    return result + 1;
}

std::string getSentecesString() {
    std::string sentencesPath = "data/sentences.txt";
    std::ifstream allSentences;
    allSentences.open(sentencesPath);

    std::string resultingString;

    while (allSentences.peek() != EOF) {
        std::string line;
        getline(allSentences, line, '*');
        resultingString.append(line);
        resultingString.append("*");
    };
    allSentences.close();
    return resultingString;
}

void addSentence() {
    Sentence sentence = Sentence();
    sentence.id = getMaxId();

    std::cout << std::endl;
    std::cout << "Created by:" << std::endl;
    std::cin.ignore();
    std::getline(std::cin, sentence.created_by);
    while (sentence.created_by.size() == 0) {
        std::cout << "Input empty! Please insert data:" << std::endl;
        std::getline(std::cin, sentence.created_by);
    };

    std::cout << std::endl;
    std::cout << "From:" << std::endl;
    std::getline(std::cin, sentence.from);
    while (sentence.from.size() == 0) {
        std::cout << "Input empty! Please insert data:" << std::endl;
        std::getline(std::cin, sentence.from);
    };

    std::cout << std::endl;
    std::cout << "Text:" << std::endl;
    std::getline(std::cin, sentence.text);
    while (sentence.text.size() == 0) {
        std::cout << "Input empty! Please insert data:" << std::endl;
        std::getline(std::cin, sentence.text);
    };

    std::string sentenceString;
    sentenceString = std::to_string(sentence.id) + '|' + sentence.created_by + '|' + sentence.from + '|' + sentence.text + '*';

    std::string currentValues = getSentecesString();
    std::ofstream sentencesFile("data/sentences.txt");
    sentencesFile << currentValues + sentenceString;
    sentencesFile.close();
}

int addScripts() {
    std::cout << std::endl;
    std::cout << "/*------------------*/" << std::endl;
    std::cout << "Add menu" << std::endl;
    std::cout << "/*------------------*/" << std::endl;
    int path {};
    while (path == 0) {
        path = menuAdd();
        if (path == 0) {
            addSentence();
        };
    };
    addReturbBack();

    return 0;
}