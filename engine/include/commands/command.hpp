#pragma once

#include <string>

namespace engine
{
    enum class EngineCommandType
    {
        Quit,
        Restart,
        ChangeScene,
        ToggleFullscreen
    };

    struct EngineCommand
    {
        EngineCommandType type;
        std::string name = "";
    };
}