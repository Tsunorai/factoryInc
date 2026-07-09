#pragma once

#include "raylib.h"

namespace engine
{
    struct MouseButton
    {
        Vector2 mousePosition;

        bool mousePressed;
        bool mouseDown;
    };

    struct KeyboardKey
    {
        bool enter;

        bool w;
        bool a;
        bool s;
        bool d;
    };

    struct Input
    {
        MouseButton mouse;
        KeyboardKey key;
    };
} // namespace engine