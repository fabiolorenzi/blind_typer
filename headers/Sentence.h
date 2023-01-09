#pragma once

#include <iostream>

class Sentence {
    public:
        int id;
        std::string created_by;
        std::string from;
        std::string text;
        Sentence();
        Sentence(int _id, std::string _created_by, std::string _from, std::string _text);
};