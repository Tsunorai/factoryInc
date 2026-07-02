#pragma once

#include <raylib.h>
#include <string>

namespace engine
{
    struct Text
    {
        std::string content;
        int fontSize;
        Font font;
        Color color;
    };
} // namespace engine