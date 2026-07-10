#pragma once

#include "world/chunk.hpp"
#include "interface/engineContext.hpp"

#include <memory>
#include <raylib.h>
#include <vector>

namespace FInc
{
    class ChunkManager
    {
    public:
        ChunkManager();
        void createNewChunk(Vector2 position);
        void update(Vector2 offset); // todo consider zoom
        void render(engine::EngineContext&);

    private:
        void generateStartChunks();

    private:
        static constexpr int GRID_SIZE = 150;
        static constexpr Vector2 CHUNK_SIZE = {64, 64};

        Vector2 screenSize;
        std::vector<std::unique_ptr<Chunk>> chunks;
    };
} // namespace FInc