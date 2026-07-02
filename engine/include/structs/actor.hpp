#pragma once

namespace engine
{
    struct Actor
    {
        virtual void update() = 0;
        virtual void render() = 0;

        virtual ~Actor() {}
    };
} // namespace engine