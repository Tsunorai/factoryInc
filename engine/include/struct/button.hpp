#pragma once

#include "struct/text.hpp"

#include <functional>
#include <raylib.h>

namespace engine
{
    struct EngineContext;
    class Button
    {
    public:
        Button(const std::function<void()>& onClick, Rectangle rect, Text label, Color btnColor = GRAY);
        void update(engine::EngineContext&);
        void render(engine::EngineContext&);

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