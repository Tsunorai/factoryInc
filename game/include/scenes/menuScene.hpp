#pragma once

#include "structs/scene.hpp"
#include "structs/button.hpp"

#include <vector>

namespace FInc
{
    class MenuScene : public engine::Scene
    {
    public:
        MenuScene();
        engine::SceneResult update() override;
        void render(const engine::Renderer& renderer) override;

        void createMenu();

    private:
        std::vector<engine::Button> buttons;
    };
} // namespace FInc