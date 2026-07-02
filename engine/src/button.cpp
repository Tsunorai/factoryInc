#include "structs/button.hpp"

namespace engine
{
    Button::Button(const float x, const float y, const float width, const float height, const Color btnColor, const std::string content, const int fontSize, const Font font, const float spacing, const Color txtColor) : normalColor(btnColor), currentColor(btnColor)
    {
        hoverColor = darken(btnColor, 0.8f);
        rect = {x, y, width, height};
        label = {content, fontSize, font, spacing, txtColor};
    };

    void Button::update()
    {
        bool isHovered = CheckCollisionPointRec(GetMousePosition(), rect);
        if (isHovered && !hideHover)
        {
            currentColor = hoverColor;
        }
        else
        {
            currentColor = normalColor;
        }
    };

    void Button::render(const Renderer& render)
    {
        render.drawButton(*this);
    };

    Color Button::darken(const Color& darken, const float factor) const
    {
        Color darkened = darken;
        darkened.r = static_cast<unsigned char>(darkened.r * factor);
        darkened.g = static_cast<unsigned char>(darkened.g * factor);
        darkened.b = static_cast<unsigned char>(darkened.b * factor);
        return darkened;
    }
} // namespace engine