#include "game.hpp"
#include "engine.hpp"
#include "scenes/menuScene.hpp"

namespace FInc
{
    void Game::init()
    {
        // load settings from file before init window
        engine.init();
        currentScene = std::make_unique<MenuScene>();
    }

    void Game::run()
    {
        while (engine.isRunning())
        {
            update();

            engine.beginFrame();
            currentScene->render(engine.getRenderer());
            engine.endFrame();
        }

        engine.clean();
    }

    void Game::update()
    {
        engine::SceneResult result = currentScene->update();

        if (result.action == engine::SceneAction::ChangeScene)
        {
            currentScene = std::move(result.newScene);
            // currentScene->init();
        }
    }
} // namespace FInc