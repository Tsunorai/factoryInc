#pragma once

#include "structs/scene.hpp"

namespace FInc
{
    class GameScene : public engine::Scene
    {
    public:
        GameScene();
        engine::SceneResult update() override;
        void render(const engine::Renderer& renderer) override;
    };
} // namespace FInc