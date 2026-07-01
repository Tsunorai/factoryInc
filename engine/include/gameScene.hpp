#pragma once

#include <entity.hpp>
#include <scene.hpp>

#include <memory>
#include <vector>

namespace engine
{
    class GameScene : public Scene
    {
    public:
        SceneResult update() override;
        void render(const Renderer& renderer) override;

    private:
        std::vector<std::unique_ptr<Entity>> entities{};
    };
} // namespace engine