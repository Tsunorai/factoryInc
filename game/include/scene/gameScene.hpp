#pragma once

#include "scene/iScene.hpp"

namespace FInc
{
    class GameScene : public engine::IScene
    {
    public:
        GameScene();
        void update(engine::EngineContext&) override;
        void render(engine::EngineContext&) override;
        void exit() override {};
        void enter() override {};
    };
} // namespace FInc