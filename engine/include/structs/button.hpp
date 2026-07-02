#pragma once

#include "structs/actor.hpp"
#include "structs/text.hpp"

#include <raylib.h>

namespace engine
{
    class Button : public Actor
    {
    public:
        Button(const float x, const float y, const float width, const float height, const Color btnColor, const std::string content, const Color txtColor = WHITE, const int fontSize = 20, const Font font = GetFontDefault()) : color(btnColor)
        {
            rect = {x, y, width, height};
            label = {content, fontSize, font, txtColor};
        };
        void update() override {};
        void render() override {};

        Rectangle rect;
        Color color;
        Text label;
    };
} // namespace engine