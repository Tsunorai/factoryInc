#pragma once

#include "actor.hpp"
#include "render.hpp"

#include <memory>
#include <vector>

namespace engine
{
    struct SceneResult;

    struct Scene
    {
        virtual SceneResult update() = 0;
        virtual void render(const Renderer& renderer) = 0;

        virtual ~Scene() {}

        std::vector<std::unique_ptr<engine::Actor>> actors;
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