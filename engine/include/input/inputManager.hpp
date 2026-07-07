#pragma once

#include "inputState.hpp"

namespace engine
{
    class InputManager
    {
    public:
        InputState pollInput();
        void pollMouseInput(InputState& input);
        void pollKeyboardInput(InputState& input);

    };
} // namespace engine