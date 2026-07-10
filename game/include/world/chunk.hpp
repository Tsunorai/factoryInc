#pragma once

#include "interface/engineContext.hpp"
#include <raylib.h>
namespace FInc
{
    struct Chunk
    {
        void update(engine::EngineContext&);
        void render(engine::EngineContext&);
        Vector2 globalPosition;
        Vector2 position;
        int height, width;
    };

} // namespace FInc