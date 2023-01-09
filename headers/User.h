#pragma once

class User {
    public:
        int id;
        int minSpeed;
        int maxSpeed;
        int averageSpeed;
        int sessionsFinished;
        User();
        User(int _id, int _minSpeed, int _maxSpeed, int _averageSpeed, int _sessionsFinished);
};