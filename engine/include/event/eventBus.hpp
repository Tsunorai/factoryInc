#pragma once

#include "event/iEvent.hpp"
#include <functional>
#include <typeindex>
#include <unordered_map>
#include <vector>

namespace engine
{
    class EventBus
    {
    public:
        template <typename Event>
            requires std::derived_from<Event, IEvent>
        void publish(const Event& event)
        {
            iterator it = listeners.find(typeid(Event));

            if (it == listeners.end())
            {
                return;
            }

            // add safety barrier to not subscribe on publishing same event. if engine survives.
            std::vector<Callback>& callbacks = it->second;

            for (Callback& callback : callbacks)
            {
                callback(&event);
            }
        }

        template <typename Event>
            requires std::derived_from<Event, IEvent>
        void subscribe(std::function<void(const Event& event)> callback)
        {
            listeners[typeid(Event)].push_back(
                [callback](const void* event) {
                    callback(*static_cast<const Event*>(event));
                });
        }

        // todo create unsubscribe

    private:
        using Callback = std::function<void(const void*)>;
        using iterator = std::unordered_map<
            std::type_index,
            std::vector<Callback>>::iterator;

        std::unordered_map<
            std::type_index,
            std::vector<Callback>>
            listeners;
    };
} // namespace engine