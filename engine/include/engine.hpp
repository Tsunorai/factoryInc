#pragma once

#include "input/inputManager.hpp"
#include "interface/iEngineContext.hpp"
#include "render/render.hpp"

namespace engine
{
    struct IGame;
    struct EngineCommand;
    struct Engine : IEngineContext
    {
        void init();
        void run(IGame& game);
        void shutdown();
        void clean();

        void processCommand(const EngineCommand& command);

        void beginFrame();
        void endFrame();

        bool isRunning();

        const Renderer& getRenderer() const;

    private:
        void sendCommand(const EngineCommand command) override;

    private:
        Renderer renderer;
        InputManager inputManager;
        bool exitRequested = false;
    };
} // namespace engine