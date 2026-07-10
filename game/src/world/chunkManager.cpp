#pragma once

#include "world/chunkManager.hpp"
#include "engineMapper.hpp"
#include "world/chunk.hpp"
#include <algorithm>
#include <cstddef>
#include <execution>
#include <memory>
#include <ranges>
#include <raylib.h>
#include <vector>

namespace FInc
{
    ChunkManager::ChunkManager()
    {
        screenSize = {
            static_cast<float>(engine::getScreenHeight()),
            static_cast<float>(engine::getScreenWidth())};

        generateStartChunks();
    }

    void ChunkManager::generateStartChunks()
    {
        short numVertical = screenSize.x / CHUNK_SIZE.x * GRID_SIZE + 1;
        short numHorizontal = screenSize.y / CHUNK_SIZE.y * GRID_SIZE + 1;

        for (size_t i; i < numHorizontal * numVertical; i++)
        {
        }
    }

    void ChunkManager::update(Vector2 offset)
    {
        std::for_each(std::execution::par, chunks.begin(), chunks.end(), [&offset](std::unique_ptr<Chunk>& chunk) {
            chunk->position.x = chunk->globalPosition.x + offset.x;
            chunk->position.y = chunk->globalPosition.y + offset.y;
        });
    }

    void ChunkManager::render(engine::EngineContext& engine)
    {
        auto toRender = chunks | std::views::filter([this](std::unique_ptr<Chunk>& chunk) {
                            const bool isInWidth = chunk->position.x < screenSize.x + 200 && chunk->position.x > -200;
                            const bool isInHeight = chunk->position.y < screenSize.y + 200 && chunk->position.y > -200;
                            return isInWidth && isInHeight;
                        });
        std::for_each(std::execution::par, toRender.begin(), toRender.end(), [&engine](std::unique_ptr<Chunk>& chunk) {
            chunk->render(engine);
        });
    }
} // namespace FInc