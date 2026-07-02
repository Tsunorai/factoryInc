#pragma once

#include "structs/scene.hpp"

namespace FInc
{
    class MenuScene : public engine::Scene
    {
    public:
        MenuScene();
        engine::SceneResult update() override;
        void render(const engine::Renderer& renderer) override;

        void createMenu();
    };
} // namespace FInc