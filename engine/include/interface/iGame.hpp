#pragma once

namespace engine
{
    struct EngineContext;
    struct IGame
    {
        virtual ~IGame() = default;

        virtual void init(EngineContext& ctx) = 0;
        virtual void update(EngineContext& ctx) = 0;
        virtual void render(EngineContext& ctx) = 0;
        virtual void shutdown() = 0;
    };
} // namespace engine