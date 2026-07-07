#pragma once

#include "interface/iEngineContext.hpp"
#include "interface/iGame.hpp"
#include "structs/scene.hpp"
#include "render/render.hpp"

#include <memory>

namespace FInc
{
    struct Game : engine::IGame
    {
    public:
        void init(engine::IEngineContext& context) override;

    private:
        void update(const engine::InputState& input, const float deltaTime) override;
        void render(const engine::Renderer& renderer) override;
        void shutdown() override {};

    private:
        engine::IEngineContext* engineContext{};

        std::unique_ptr<engine::Scene> currentScene;
    };
} // namespace FInc