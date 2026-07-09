#pragma once

#include "render/render.hpp"

namespace engine
{
    struct InputState;
    struct Actor
    {
        virtual void update(const engine::InputState& input) = 0;
        virtual void render(const Renderer& render) = 0;

        virtual ~Actor() {}
    };
} // namespace engine