#pragma once

#include "structs/actor.hpp"
#include "structs/text.hpp"

#include <raylib.h>

namespace engine
{
    class Button : public Actor
    {
    public:
        Button(const float x, const float y, const float width, const float height, const Color btnColor, const std::string content, const int fontSize = 20, const Font font = GetFontDefault(), const float spacing = 1.0f, const Color txtColor = WHITE) : color(btnColor)
        {
            rect = {x, y, width, height};
            label = {content, fontSize, font, spacing, txtColor};
        };
        void update() override {};
        void render(const Renderer& render) override
        {
            render.drawButton(*this);
        };

        Rectangle rect;
        Color color;
        Text label;
    };
} // namespace engine