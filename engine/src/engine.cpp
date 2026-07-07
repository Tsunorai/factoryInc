#include "engine.hpp"

#include "commands/command.hpp"
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
            game.update(inputManager.pollInput(), GetFrameTime());

            for (auto& command : commands.consume())
            {
                processCommand(command);
            }

            beginFrame();
            game.render(renderer);

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

    void Engine::sendCommand(const EngineCommand command)
    {
        commands.push(command);
    }

    void Engine::processCommand(const EngineCommand& command)
    {
        switch (command.type)
        {
        case EngineCommandType::Quit:
            shutdown();
            break;

        case EngineCommandType::Restart:
            break;

        case EngineCommandType::ToggleFullscreen:
            break;
        default:
            break;
        }
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