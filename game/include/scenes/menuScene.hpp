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

    public:
        engine::SceneResult sceneResult = {engine::SceneAction::None};
    private:
        void createMenu();
    };
} // namespace FInc