#include "engine.hpp"

#include <raylib.h>

namespace engine
{
    void Engine::init()
    {
        InitWindow(1920, 1080, "Factory Inc.");
        SetExitKey(KEY_NULL);
    }

    void Engine::shutdown()
    {
        exitRequested = true;
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
        return !exitRequested && !WindowShouldClose();
    }
} // namespace engine