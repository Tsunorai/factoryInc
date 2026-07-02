#pragma once

#include "structs/button.hpp"

namespace engine
{
    struct Renderer
    {
        void beginFrame() const;
        void endFrame() const;
        void drawBackground(const Color& color) const;
        void drawGrid() const;
        void drawButton(const Button& button) const;
    };
} // namespace engine