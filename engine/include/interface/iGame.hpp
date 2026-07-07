#pragma once

namespace engine
{
    struct InputState;
    struct IEngineContext;
    struct Renderer;
    struct IGame
    {
        virtual ~IGame() = default;

        virtual void init(IEngineContext& context) = 0;
        virtual void update(const InputState& input, const float deltaTime) = 0;
        virtual void render(const Renderer& renderer) = 0;
        virtual void shutdown() = 0;
    };
} // namespace engine