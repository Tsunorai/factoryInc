#pragma once

namespace engine
{
    struct EngineContext;

    struct IScene
    {
        virtual void enter() = 0;

        virtual void exit() = 0;

        virtual void update(EngineContext&) = 0;

        virtual void render(EngineContext&) = 0;

        virtual ~IScene() = default;
    };

} // namespace engine