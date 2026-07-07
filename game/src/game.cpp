#include "game.hpp"

#include "commands/command.hpp"
#include "input/inputState.hpp"
#include "scenes/menuScene.hpp"

#include <utility>

namespace FInc
{
    void Game::init(engine::IEngineContext& context)
    {
        engineContext = &context;
        // load settings from file before init window
        currentScene = std::make_unique<MenuScene>();
    }

    void Game::update(const engine::InputState& input, const float deltaTime)
    {
        engine::SceneResult result = currentScene->update(input);

        if (result.action == engine::SceneAction::ChangeScene)
        {
            currentScene = std::move(result.newScene);
            // currentScene->init();
        }
        else if (result.action == engine::SceneAction::Quit)
        {
            engineContext->sendCommand(engine::EngineCommand(engine::EngineCommandType::Quit));
        }
    }

    void Game::render(const engine::Renderer& renderer)
    {
        currentScene->render(renderer);
    }
} // namespace FInc