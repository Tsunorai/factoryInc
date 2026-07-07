#include "scenes/gameScene.hpp"

#include "scenes/menuScene.hpp"
#include "engineMapping.hpp"

#include <iostream>
#include <memory>

namespace FInc
{
    GameScene::GameScene()
    {
        std::cout << "GameScene created" << std::endl;
    }

    engine::SceneResult GameScene::update(const engine::InputState& input)
    {
        // replace when a overlay is implemented
        if (input.key.enter)
        {
            return {engine::SceneAction::ChangeScene, std::move(std::make_unique<MenuScene>())};
        }
        return {engine::SceneAction::None};
    }

    void GameScene::render(const engine::Renderer& renderer)
    {
        renderer.drawBackground(BLACK);
    }
} // namespace FInc

