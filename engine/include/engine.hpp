#pragma once

#include "input/inputManager.hpp"
#include "interface/engineContext.hpp"

namespace engine
{
    struct IGame;
    struct ICommand;
    class Engine : public EngineContext
    {
    public:
        Engine() = default;
        void init();
        void run(IGame& game);
        void shutdown();

    private:
        void clean();

        void beginFrame();
        void endFrame();

        bool isRunning();

    private:
        bool exitRequested = false;
        InputManager inputManager;
    };
} // namespace engine