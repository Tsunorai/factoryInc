#include "game.hpp"
#include "engine.hpp"

#include <raylib.h>

namespace FInc
{
    void Game::init()
    {
        engine.init();
    }

    void Game::run()
    {
        while (engine.isRunning())
        {
            engine::SceneResult result = currentScene->update();

            if (result.action == engine::SceneAction::ChangeScene)
            {
                currentScene = std::move(result.newScene);
                // currentScene->init();
            }

            engine.beginFrame();
            currentScene->render(engine.getRenderer());
            engine.endFrame();
        }

        engine.clean();
    }
} // namespace FInc