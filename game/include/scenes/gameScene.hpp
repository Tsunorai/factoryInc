#pragma once

#include "structs/actor.hpp"
#include "structs/scene.hpp"

#include <memory>
#include <vector>

namespace FInc
{
    class GameScene : public engine::Scene
    {
    public:
        GameScene();
        engine::SceneResult update() override;
        void render(const engine::Renderer& renderer) override;

    private:
        std::vector<std::unique_ptr<engine::Actor>> entities{};
    };
} // namespace FInc