#include "render.hpp"

#include <raylib.h>

namespace engine
{
    void Renderer::beginFrame()
    {
        BeginDrawing();
    }

    void Renderer::endFrame()
    {
        EndDrawing();
    }

    void Renderer::drawGrid()
    {
        // Implementation for drawing a grid
    }
} // namespace engine