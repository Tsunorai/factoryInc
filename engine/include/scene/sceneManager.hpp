#pragma once

#include "iScene.hpp"

#include <memory>

namespace engine
{
    class SceneManager
    {
    public:
        void setStartScene(std::unique_ptr<IScene> scene);
        void loadScene(std::unique_ptr<IScene> scene);
        void changeScene(std::unique_ptr<IScene> scene);

        void update(EngineContext& ctx);
        void render(EngineContext& ctx);

    private:
        std::unique_ptr<IScene> currentScene;
    };
} // namespace engine