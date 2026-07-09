#pragma once

#include "raylib.h"

namespace engine
{
    struct MouseButton
    {
        Vector2 mousePosition{0, 0};
        
        bool mousePressed = false;
        bool mouseDown = false;
    };

    struct KeyboardKey
    {
        bool enter = false;
        bool w = false;
        bool a = false;
        bool s = false;
        bool d = false;
    };

    struct Input
    {
        MouseButton mouse;
        KeyboardKey key;
    };
} // namespace engine