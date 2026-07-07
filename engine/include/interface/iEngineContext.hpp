#pragma once

#include "commands/commandQueue.hpp"

namespace engine
{
    struct EngineCommand;
    struct IEngineContext
    {
        virtual ~IEngineContext() = default;
        virtual void sendCommand(EngineCommand command) = 0;

    protected:
        CommandQueue commands;
    };
} // namespace engine