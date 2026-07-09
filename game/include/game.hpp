#pragma once

#include "interface/engineContext.hpp"
#include "interface/iGame.hpp"

namespace FInc
{
    struct Game : engine::IGame
    {
    public:
        void init(engine::EngineContext& ctx) override;

    private:
        void update(engine::EngineContext& ctx) override;
        void render(engine::EngineContext& ctx) override;
        void shutdown() override {};
    };
} // namespace FInc