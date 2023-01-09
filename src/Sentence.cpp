#include <iostream>
#include "../headers/Sentence.h"

Sentence::Sentence(std::string _id, std::string _created_by, std::string _text) {
    this->id = _id;
    this->created_by = _created_by;
    this->text = _text;
}