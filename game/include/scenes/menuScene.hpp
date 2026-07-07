#pragma once

#include "structs/scene.hpp"

namespace FInc
{
    class MenuScene : public engine::Scene
    {
    public:
        MenuScene();
        engine::SceneResult update(const engine::InputState& input) override;
        void render(const engine::Renderer& renderer) override;
    private:
        void createMenu();
    };
} // namespace FInc