#pragma once

#include "render.hpp"

namespace engine
{
    struct Actor
    {
        virtual void update() = 0;
        virtual void render(const Renderer& render) = 0;

        virtual ~Actor() {}
    };
} // namespace engine