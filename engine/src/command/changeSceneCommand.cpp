#include "command/changeSceneCommand.hpp"

#include "engine.hpp"
#include "scene/sceneManager.hpp"

namespace engine
{
    ChangeSceneCommand::ChangeSceneCommand(std::unique_ptr<IScene> scene)
        : newScene(std::move(scene))
    {
    }

    void ChangeSceneCommand::execute(Engine& engine)
    {
        engine.scenes.changeScene(std::move(newScene));
    }

} // namespace engine