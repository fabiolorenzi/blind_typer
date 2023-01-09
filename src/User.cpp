#include "../headers/User.h"

User::User() {
    this->id = -1;
    this->minSpeed = 0;
    this->maxSpeed = 0;
    this->averageSpeed = 0;
    this->sessionsFinished = 0;
}

User::User(int _id, int _minSpeed, int _maxSpeed, int _averageSpeed, int _sessionFinished) {
    this->id = _id;
    this->minSpeed = _minSpeed;
    this->maxSpeed = _maxSpeed;
    this->averageSpeed = _averageSpeed;
    this->sessionsFinished = _sessionFinished;
}