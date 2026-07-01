#pragma once

#include <render.hpp>

#include <memory>

namespace engine
{
    struct SceneResult;
    
    struct Scene
    {
        virtual SceneResult update() = 0;
        virtual void render(const Renderer& renderer) = 0;

        virtual ~Scene() {}
    };

    enum class SceneAction
    {
        None,
        ChangeScene,
        Quit
    };

    struct SceneResult
    {
        SceneAction action = SceneAction::None;
        std::unique_ptr<Scene> newScene;
    };

} // namespace engine