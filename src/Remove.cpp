#include <iostream>
#include <fstream>
#include <istream>
#include <sstream>
#include <string>
#include <vector>
#include "../headers/Remove.h"
#include "../headers/Sentence.h"

int menuRemove() {
    int decidedPath {-1};
    std::cout << std::endl;
    std::cout << "Please choose what to do:" << std::endl;
    while (decidedPath == -1) {
        std::cout << "[0] Remove Sentence, [1] Reset User, [2] Return Back" << std::endl;
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

void removeReturnBack() {
    std::cout << std::endl;
    std::cout << "/*----------------------*/" << std::endl;
    std::cout << "Welcome back to the main menu" << std::endl;
    std::cout << "/*----------------------*/" << std::endl;
}

std::vector<Sentence> getSentences() {
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

        // Below here we are working on the single line
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

void removeSentence() {
    int decision {};
    std::cout << std::endl;
    std::cout << "Which sentence you want to remove?" << std::endl;
    std::cout << "Please insert its id. Leave empty to undo." << std::endl;
    std::cin >> decision;
    if (decision >= 0) {
        std::vector<Sentence> allSentences = getSentences();
        if (allSentences.size() > 0) { 
            int index {0};  
            int preciseIndex {};       
            Sentence selectedSentence;
            for(Sentence sent : allSentences) {
                if (decision == sent.id) {
                    selectedSentence = sent;
                    preciseIndex = index;
                } else {
                    ++index;
                };
            };
            if (selectedSentence.id) {
                int finalDecision {-1};
                std::cout << std::endl;
                std::cout << "ID: " << selectedSentence.id << std::endl;
                std::cout << "Created by: " << selectedSentence.created_by << std::endl;
                std::cout << "From: " << selectedSentence.from << std::endl;
                std::cout << "Text: " << selectedSentence.text << std::endl;
                std::cout << "Are you sure you want to delete this sentence?" << std::endl;
                std::cout << "[0] Yes, [1] No" << std::endl;
                std::cin >> finalDecision;
                if (finalDecision == 0) {
                    allSentences.erase(allSentences.begin() + preciseIndex);
                    std::string resultingString;
                    for(Sentence sentence : allSentences) {
                        std::string sentenceString = std::to_string(sentence.id) + '|' + sentence.created_by + '|' + sentence.from + '|' + sentence.text + '*';
                        resultingString.append(sentenceString);
                    };
                    std::ofstream sentencesFile("data/sentences.txt");
                    sentencesFile << resultingString;
                    sentencesFile.close();
                    std::cout << std::endl;
                    std::cout << "Sentence removed successfully" << std::endl;
                };
            } else {
                std::cout << std::endl;
                std::cout << "Sentence not found" << std::endl;
                std::cout << std::endl;
            };
        } else {
            std::cout << std::endl;
            std::cout << "There are no sentences available" << std::endl;
            std::cout << std::endl;
        };
    };
}

void resetUser() {
    int decision {};
    std::cout << std::endl;
    std::cout << "Are you sure you want to reset the user data?" << std::endl;
    std::cout << "[0] Yes, [1] No" << std::endl;
    std::cin >> decision;
    if (decision == 0) {
        std::ofstream userFile("data/user.txt");
        std::string newUserString = "0|0|0|0|0";
        userFile << newUserString;
        remove("data/results.txt");
        std::cout << std::endl;
        std::cout << "The user has been reset successfully." << std::endl;
    };
}

int removeScripts() {
    std::cout << std::endl;
    std::cout << "/*------------------*/" << std::endl;
    std::cout << "Remove Menu" << std::endl;
    std::cout << "/*------------------*/" << std::endl;
    int path {};
    while (path != 2) {
        path = menuRemove();
        switch(path) {
            case 0:
                removeSentence();
                break;
            case 1:
                resetUser();
                break;
        };
    };
    removeReturnBack();

    return 0;
}