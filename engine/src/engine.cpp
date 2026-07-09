#include "engine.hpp"

#include "command/iCommand.hpp"
#include "interface/iGame.hpp"
#include "render/render.hpp"

#include <iostream>
#include <raylib.h>

namespace engine
{
    void Engine::init()
    {
        InitWindow(1920, 1080, "Factory Inc.");
        SetExitKey(KEY_NULL);
    }

    void Engine::run(IGame& game)
    {
        std::cout << "Engine Start " << this << std::endl;

        game.init(*this);

        while (isRunning())
        {
            deltaTime = GetFrameTime();
            input = inputManager.pollInput();

            game.update(*this);
            commands.execute(*this);

            beginFrame();
            game.render(*this);
            endFrame();
        }

        game.shutdown();
        clean();
    }

    void Engine::shutdown()
    {
        exitRequested = true;
    }

    void Engine::clean()
    {
        std::cout << "clean" << std::endl;

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

    bool Engine::isRunning()
    {
        return !exitRequested && !WindowShouldClose();
    }
} // namespace engine