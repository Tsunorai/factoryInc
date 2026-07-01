#pragma once

#include "scene.hpp"
#include <engine.hpp>
#include <memory>

namespace FInc
{
    struct Game
    {
        void init();
        void run();

    private:
        engine::Engine engine;
        std::unique_ptr<engine::Scene> currentScene;
    };
} // namespace FInc