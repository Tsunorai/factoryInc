#include "engine.hpp"

#include <raylib.h>

namespace engine
{
    void Engine::init()
    {
        InitWindow(800, 600, "Factory Inc.");
    }

    void Engine::clean()
    {
        CloseWindow();
    }

    void Engine::beginFrame()
    {
        renderer.beginFrame();
    }

    void Engine::endFrame()
    {
        renderer.endFrame();
    }

    const Renderer& Engine::getRenderer() const
    {
        return renderer;
    }

    bool Engine::isRunning()
    {
        return !WindowShouldClose();
    }
} // namespace engine