#pragma once

#include <raylib.h>
#include <string>

namespace engine
{
    struct Text
    {
        Text(std::string content, const int fontSize = 20, const Font font = GetFontDefault(), const float spacing = 1.0f, const Color color = WHITE)
            : content(std::move(content)), fontSize(fontSize), font(font), spacing(spacing), color(color) {};
        std::string content;
        int fontSize;
        Font font;
        float spacing;
        Color color;
    };
} // namespace engine