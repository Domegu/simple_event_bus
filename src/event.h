#pragma once

class Event {
public:
    Event(int time, void* data): _time(time), _data(data) {}
    virtual ~Event() {}

    int getTime() const {
        return _time;
    }

    void* getData() const {
        return _data;
    }

private:
    int _time;
    void* _data;
};
