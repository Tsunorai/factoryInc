#include "game.hpp"

#include "scene/menuScene.hpp"

namespace FInc
{
    void Game::init(engine::EngineContext& ctx)
    {
        ctx.scenes.setStartScene(std::make_unique<MenuScene>(ctx));
    }

    void Game::update(engine::EngineContext& ctx)
    {
        ctx.scenes.update(ctx);
    }

    void Game::render(engine::EngineContext& ctx)
    {
        ctx.scenes.render(ctx);
    }
} // namespace FInc