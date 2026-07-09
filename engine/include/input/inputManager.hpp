#pragma once

#include "input.hpp"

namespace engine
{
    class InputManager
    {
    public:
        Input pollInput();
        void pollMouseInput(Input& input);
        void pollKeyboardInput(Input& input);

    };
} // namespace engine