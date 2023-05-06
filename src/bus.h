#pragma once

#include <map>
#include <set>
#include <memory>
#include "event.h"
#include "observer.h"

class Bus {
public:
    Bus() = default;
    ~Bus() = default;

    void registerObserver(std::shared_ptr<Observer> observer);
    void unregisterObserver(std::shared_ptr<Observer> observer);
    void notifyObservers(std::shared_ptr<Event> event);

private:
    std::map<std::type_index, std::set<std::shared_ptr<Observer>>> _eventToObservers;
    std::set<std::shared_ptr<Observer>> _observers;
};
