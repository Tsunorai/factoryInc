#pragma once

namespace engine
{
    struct Renderer
    {
        void beginFrame();
        void endFrame();
        void drawGrid();
    };
} // namespace engine