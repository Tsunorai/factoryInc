#include "structs/button.hpp"

#include "input/inputState.hpp"

namespace engine
{
    Button::Button(const std::function<void()>& onClick, const Rectangle rect, const Text label, const Color btnColor) : onClick(onClick), rect(rect), label(label), normalColor(btnColor), currentColor(btnColor)
    {
        hoverColor = darken(btnColor, 0.8f);
    };

    void Button::update(const engine::InputState& input)
    {
        bool isHovered = CheckCollisionPointRec(input.mouse.mousePosition, rect);
        if (isHovered && !hideHover)
        {
            currentColor = hoverColor;
        }
        else
        {
            currentColor = normalColor;
        }

        if (isHovered && input.mouse.mousePressed)
        {
            if (onClick)
            {
                onClick();
            }
        }
    };

    void Button::render(const Renderer& render)
    {
        render.drawButton(*this);
    };

    Color Button::darken(const Color& color, const float factor) const
    {
        Color darkened = color;
        darkened.r = static_cast<unsigned char>(darkened.r * factor);
        darkened.g = static_cast<unsigned char>(darkened.g * factor);
        darkened.b = static_cast<unsigned char>(darkened.b * factor);
        return darkened;
    }
} // namespace engine