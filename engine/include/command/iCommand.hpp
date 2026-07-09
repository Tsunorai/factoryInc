#pragma once

namespace engine
{
    class Engine;
    struct ICommand
    {
        virtual ~ICommand() = default;
        virtual void execute(Engine&) = 0;
    };
} // namespace engine