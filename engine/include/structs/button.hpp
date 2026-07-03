#pragma once

#include "structs/actor.hpp"
#include "structs/text.hpp"

#include <functional>
#include <raylib.h>

namespace engine
{
    class Button : public Actor
    {
    public:
        Button(const std::function<void()>& onClick, const float x, const float y, const float width, const float height, const Color btnColor, const std::string content, const int fontSize = 20, const Font font = GetFontDefault(), const float spacing = 1.0f, const Color txtColor = WHITE);
        void update() override;
        void render(const Renderer& render) override;

        Color darken(const Color& darken, const float factor) const;

        Rectangle rect;
        Color normalColor;
        Color hoverColor;
        Color currentColor;
        Text label;
        std::function<void()> onClick;

        bool hideHover = false;
    };
} // namespace engine