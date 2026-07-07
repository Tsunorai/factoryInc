#pragma once

#include "commands/command.hpp"
#include <vector>

namespace engine
{
    class CommandQueue
    {
    public:
        void push(engine::EngineCommand command);

        std::vector<engine::EngineCommand> consume();

    private:
        std::vector<engine::EngineCommand> commands;
    };
} // namespace engine
