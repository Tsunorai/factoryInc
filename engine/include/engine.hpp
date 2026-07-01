#pragma once
#include <render.hpp>

namespace engine
{
    struct Engine
    {
        void init();
        void clean();

        void beginFrame();
        void endFrame();

        const Renderer& getRenderer() const;

        bool isRunning();
    private:
        Renderer renderer;
    };
} // namespace engine