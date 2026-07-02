#pragma once

#include "engine.hpp"
#include "structs/scene.hpp"

#include <memory>

namespace FInc
{
    struct Game
    {
    public:
        void init();
        void run();

    private:
        void update();

    private:
        engine::Engine engine;
        std::unique_ptr<engine::Scene> currentScene;
    };
} // namespace FInc