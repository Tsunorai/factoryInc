#pragma once

namespace engine
{
    struct EngineContext;
    struct Actor
    {
        virtual void update(engine::EngineContext&) = 0;
        virtual void render(engine::EngineContext&) = 0;

        virtual ~Actor() {}
    };
} // namespace engine