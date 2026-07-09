#pragma once

#include "command/iCommand.hpp"
#include <memory>
#include <queue>
#include <utility>

namespace engine
{
    class CommandQueue
    {
    public:
        template <typename T, typename... Args>
            requires std::derived_from<T, ICommand>
        void enqueue(Args&&... args)
        {
            commands.push(
                std::make_unique<T>(std::forward<Args>(args)...));
        }

        void execute(Engine& engine)
        {
            
            while (!commands.empty())
            {
                commands.front()->execute(engine);
                commands.pop();
            }
        }

    private:
        std::queue<std::unique_ptr<ICommand>> commands;
    };
} // namespace engine
