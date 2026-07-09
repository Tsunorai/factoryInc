#include "scene/gameScene.hpp"

#include "command/changeSceneCommand.hpp"
#include "engineMapping.hpp"
#include "scene/menuScene.hpp"

#include <iostream>
#include <memory>

namespace FInc
{
    GameScene::GameScene()
    {
        std::cout << "GameScene created" << std::endl;
    }

    void GameScene::update(engine::EngineContext& ctx)
    {
        // replace when a overlay is implemented
        if (ctx.input.key.enter)
        {
            ctx.commands.enqueue<engine::ChangeSceneCommand>(std::make_unique<MenuScene>(ctx));
        }
    }

    void GameScene::render(engine::EngineContext& ctx)
    {
        ctx.renderer.drawBackground(BLACK);
    }
} // namespace FInc
