#include <iostream>
#include <cstdio>
#include "../rapidjson/include/rapidjson/document.h"
#include "../rapidjson/include/rapidjson/filereadstream.h"
#include "../headers/Read.h"

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
    FILE* fp = fopen("../data/sentences.json", "r");

    // The code below is to check if the file was opened successfully
    if (!fp) {
        std::cerr << "Error: unable to open the file" << std::endl;
    };

    // Read the file into a  buffer
    char readBuffer[65536];
    rapidjson::FileReadStream is(fp, readBuffer, sizeof(readBuffer));

    // The code below is to parse the JSON
    rapidjson::Document val;
    val.ParseStream(is);

    // The code below is to close the file
    fclose(fp);

    std::cout << "Created by: " << val["created_by"].GetString() << std::endl;
    std::cout << "Text: " << val["text"].GetString() << std::endl;
}

int menuScripts() {
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
                std::cout << "Temporary Read 1" << std::endl;
                break;
        };
    };
    returnBack();

    return 0;
}