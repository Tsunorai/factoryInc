#pragma once

#include <functional>
#include <typeindex>

namespace engine
{
    class EventBus
    {
    public:
        template <typename Event>
        void publish(const Event& event)
        {
            iterator it = listeners.find(typeid(Event));

            if (it == listeners.end())
            {
                return;
            }

            std::vector<Callback>& callbacks = it->second;

            for (Callback& callback : callbacks)
            {
                callback(&event);
            }
        }

        template <typename Event>
        void subscribe(std::function<void(const Event& event)> callback)
        {
            listeners[typeid(Event)].push_back(
                [callback](const void* event) {
                    callback(*static_cast<const Event*>(event));
                });
        }

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