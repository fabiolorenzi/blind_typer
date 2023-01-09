#pragma once

class User {
    public:
        int id;
        float minSpeed;
        float maxSpeed;
        float averageSpeed;
        int sessionsFinished;
        User();
        User(int _id, float _minSpeed, float _maxSpeed, float _averageSpeed, int _sessionsFinished);
};