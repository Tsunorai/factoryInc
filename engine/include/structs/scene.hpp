#pragma once

#include "actor.hpp"
#include "input/inputState.hpp"
#include "render/render.hpp"

#include <memory>
#include <vector>

namespace engine
{
    struct Scene;
    struct InputState;

    enum class SceneAction
    {
        None,
        ChangeScene,
        Quit
    };

    struct SceneResult
    {
        SceneAction action = SceneAction::None;
        std::unique_ptr<Scene> newScene {};
    };

    struct Scene
    {
        virtual SceneResult update(const engine::InputState& input) = 0;
        virtual void render(const Renderer& renderer) = 0;

        virtual ~Scene() = default;

        std::vector<std::unique_ptr<engine::Actor>> actors;
        engine::SceneResult sceneResult = {engine::SceneAction::None};
    };

} // namespace engine