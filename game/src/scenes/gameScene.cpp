#include "scenes/gameScene.hpp"

#include "scenes/menuScene.hpp"
#include "engineMapping.hpp"
#include "structs/keys.hpp"

#include <iostream>
#include <memory>

namespace FInc
{
    GameScene::GameScene()
    {
        std::cout << "GameScene created" << std::endl;
    }

    engine::SceneResult GameScene::update()
    {
        if (engine::isKeyPressed(engine::KEY_ENTER))
        {
            return {engine::SceneAction::ChangeScene, std::move(std::make_unique<MenuScene>())};
        }
        return {engine::SceneAction::None};
    }

    void GameScene::render(const engine::Renderer& renderer)
    {
        renderer.drawBackground(BLUE);
    }
} // namespace FInc