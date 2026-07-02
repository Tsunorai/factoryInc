#include "render.hpp"

#include <raylib.h>

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
        DrawRectangle(button.rect.x, button.rect.y, button.rect.width, button.rect.height, button.color);
        Vector2 textSize = MeasureTextEx(GetFontDefault(), button.label.content.c_str(), button.label.fontSize, 1.0f);
        DrawText(button.label.content.c_str(), button.rect.x + (button.rect.width - textSize.x) / 2, button.rect.y + (button.rect.height - textSize.y) / 2, button.label.fontSize, button.label.color);
    }

} // namespace engine