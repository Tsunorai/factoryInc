#pragma once

#include "commands/commandQueue.hpp"

namespace engine
{
    struct EngineCommand;
    struct IEngineContext
    {
        ~IEngineContext() = default;
        virtual void sendCommand(EngineCommand command) = 0;

        CommandQueue commands;
    };
} // namespace engine