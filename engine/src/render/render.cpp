#include "render/render.hpp"

#include "structs/button.hpp"

namespace engine
{
    void Renderer::beginFrame() const
    {
        BeginDrawing();
    }

    void Renderer::endFrame() const
    {
        EndDrawing();
    }

    void Renderer::drawBackground(const Color& color) const
    {
        ClearBackground(color);
    }

    void Renderer::drawGrid() const
    {
        // Implementation for drawing a grid
    }

    void Renderer::drawButton(const Button& button) const
    {
        DrawRectangle(button.rect.x, button.rect.y, button.rect.width, button.rect.height, button.currentColor);

        Vector2 textSize = MeasureTextEx(GetFontDefault(), button.label.content.c_str(), button.label.fontSize, button.label.spacing);
        Vector2 textPosition = {button.rect.x + (button.rect.width - textSize.x) / 2, button.rect.y + (button.rect.height - textSize.y) / 2};
        DrawTextEx(button.label.font, button.label.content.c_str(), textPosition, button.label.fontSize, button.label.spacing, button.label.color);
    }

} // namespace engine