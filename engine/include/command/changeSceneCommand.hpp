#pragma once

#include "command/iCommand.hpp"
#include "scene/iScene.hpp"
#include <memory>

namespace engine
{
    struct ChangeSceneCommand : ICommand
    {
        ChangeSceneCommand(std::unique_ptr<IScene> scene);

        void execute(Engine& engine) override;

    private:
        std::unique_ptr<IScene> newScene;
    };
} // namespace engine