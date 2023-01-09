#pragma once

#include <iostream>

class Sentence {
    public:
        std::string id;
        std::string created_by;
        std::string text;
        Sentence(std::string _id, std::string _created_by, std::string _text);
};