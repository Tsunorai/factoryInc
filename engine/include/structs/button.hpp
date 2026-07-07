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
        Button(const std::function<void()>& onClick, Rectangle rect, Text label, Color btnColor = GRAY);
        void update(const engine::InputState& input) override;
        void render(const Renderer& render) override;

        Color darken(const Color& color, const float factor) const;

        std::function<void()> onClick;
        Rectangle rect;
        Text label;
        Color normalColor;
        Color hoverColor;
        Color currentColor;

        bool hideHover = false;
    };
} // namespace engine