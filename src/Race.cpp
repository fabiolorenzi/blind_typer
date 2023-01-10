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

int getAverage(int speed) {
    std::string resultsPath = "data/results.txt";
    std::ifstream resultsData;
    resultsData.open(resultsPath);
    if (resultsData.fail()) {
        std::ofstream resultsFile("data/results.txt");
        resultsFile << std::to_string(speed);
        resultsFile.close();
        return speed;
    } else {
        std::vector<int> tempResults;
        std::string temp;
        while (std::getline(resultsData, temp, '|')) {
            tempResults.push_back(std::stoi(temp));
        };

        // The code below is to update the file
        std::string resultString;
        int total {};
        for(int res : tempResults) {
            resultString.append(std::to_string(res) + '|');
            total += res;
        };
        resultString.append(std::to_string(speed));
        std::ofstream resultsFile("data/results.txt");
        resultsFile << resultString;
        resultsFile.close();
        
        // The code below is the real calculation
        total += speed;
        return (total / (tempResults.size() + 1));
    };
};

void updateUser(int speed) {
    std::string userPath = "data/user.txt";
    std::ifstream userData;
    userData.open(userPath);
    User user;

    if (userData.fail()) {
        user = User(0, speed, speed, speed, 1);
    } else {
        std::vector<int> tempValues;
        std::string temp;
        while (std::getline(userData, temp, '|')) {
            tempValues.push_back(std::stoi(temp));
        };
        user = User(tempValues[0], tempValues[1], tempValues[2], tempValues[3], tempValues[4]);
        user.averageSpeed = getAverage(speed);
        if (user.minSpeed > speed || user.minSpeed == 0) {
            user.minSpeed = speed;
        };
        if (user.maxSpeed < speed) {
            user.maxSpeed = speed;
        };
        user.sessionsFinished += 1;
        userData.close();
    };
    std::ofstream userFile("data/user.txt");
    std::string userString = std::to_string(user.id) + '|' + std::to_string(user.minSpeed) + '|' + std::to_string(user.maxSpeed) + '|' + std::to_string(user.averageSpeed) + '|' + std::to_string(user.sessionsFinished);
    userFile << userString;
    userFile.close();
    std::cout << "Session saved successfully" << std::endl;
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
            float speed = float(sentence.text.length() / 5) / (float(timeResult) / float(60));
            std::cout << std::endl;
            std::cout << "You time is: " << timeResult << "s" << std::endl;
            std::cout << "Your speed was: " << int(speed) << "wpm" << std::endl;
            updateUser(int(speed));
            std::cout << std::endl;
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