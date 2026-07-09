#pragma once

#include "input/inputManager.hpp"
#include "interface/engineContext.hpp"
#include "render/render.hpp"

namespace engine
{
    struct IGame;
    struct ICommand;
    class Engine : public EngineContext
    {
    public:
        Engine()
            : EngineContext{
                  input,
                  commands,
                  events,
                  scenes,
                  renderer,
                  0.0f}
        {
        }
        void init();
        void run(IGame& game);
        void shutdown();

    private:
        void clean();

        void beginFrame();
        void endFrame();

        bool isRunning();

    public:
        Input input{};

        InputManager inputManager;
        CommandQueue commands;
        EventBus events;
        SceneManager scenes;
        Renderer renderer;

    private:
        bool exitRequested = false;
    };
} // namespace engine