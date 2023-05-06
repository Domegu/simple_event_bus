#include "bus.h"

void Bus::registerObserver(std::shared_ptr<Observer> observer) {
    if(_observers.find(observer) != _observers.end()) {
        return;
    }
    _observers.insert(observer);
    for (const auto& eventType : observer->getEventTypes()) {
        _eventToObservers[eventType].insert(observer);
    }
}

void Bus::unregisterObserver(std::shared_ptr<Observer> observer) {
    _observers.erase(observer);
    for (const auto& eventType : observer->getEventTypes()) {
        _eventToObservers[eventType].erase(observer);
    }
}

void Bus::notifyObservers(std::shared_ptr<Event> event) {
    for (const auto& observer : _eventToObservers[typeid(*event)]) {
        observer->notify(event->getData());
    }
}

// Path: src/observer.cpp