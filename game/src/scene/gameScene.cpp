#include "scene/gameScene.hpp"

#include "command/changeSceneCommand.hpp"
#include "engineMapper.hpp"
#include "scene/menuScene.hpp"

#include <iostream>
#include <memory>

namespace FInc
{
    GameScene::GameScene()
    {
        std::cout << "GameScene created" << std::endl;
    }

    void GameScene::enter()
    {
        // load textures and stuff
        std::cout << "GameScene::enter" << std::endl;
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
        renderBackground(ctx);
        renderEntities(ctx);
    }

    void GameScene::renderBackground(engine::EngineContext& ctx)
    {
        ctx.renderer.drawBackground(GRAY);
        // todo grid
    }

    void GameScene::renderEntities(engine::EngineContext& ctx)
    {
        // todo maschines and entities
    }

    void GameScene::exit()
    {
        std::cout << "GameScene::exit" << std::endl;
    }
} // namespace FInc
