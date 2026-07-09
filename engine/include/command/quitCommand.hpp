#pragma once

#include "command/iCommand.hpp"

namespace engine
{
    struct QuitCommand : ICommand
    {
        QuitCommand() = default;
        void execute(Engine& engine) override;
    };
} // namespace engine