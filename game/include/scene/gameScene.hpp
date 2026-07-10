#pragma once

#include "scene/iScene.hpp"

namespace FInc
{
    class GameScene : public engine::IScene
    {
    public:
        GameScene();
        void enter() override;
        void update(engine::EngineContext&) override;
        void render(engine::EngineContext&) override;
        void exit() override;

    private:
        void renderBackground(engine::EngineContext& ctx);
        void renderEntities(engine::EngineContext& ctx);

    private:
        // chunks/tiles
    };
} // namespace FInc