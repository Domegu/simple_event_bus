#pragma once

#include <vector>
#include <typeinfo>
#include <typeindex>
#include <typeinfo>
#include <type_traits>
#include "event.h"

class Observer {
public:
    Observer(const std::vector<std::type_index>& eventTypes) {
        for (const auto& eventType : eventTypes) {
            _events.push_back(eventType);
        }
    }
    virtual ~Observer() {}

    const std::vector<std::type_index>& getEventTypes() const {
        return _events;
    }

    virtual void notify(void* data) = 0;

private:
    std::vector<std::type_index> _events;
};
