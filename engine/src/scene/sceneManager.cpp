#include "scene/sceneManager.hpp"
#include <utility>

namespace engine
{
    void SceneManager::setStartScene(std::unique_ptr<IScene> scene)
    {
        loadScene(std::move(scene));
    }

    void SceneManager::loadScene(std::unique_ptr<IScene> scene)
    {
        currentScene = std::move(scene);
        currentScene->enter();
    }

    void SceneManager::changeScene(std::unique_ptr<IScene> scene)
    {
        currentScene->exit();
        loadScene(std::move(scene));
    }

    void SceneManager::update(EngineContext& ctx)
    {
        currentScene->update(ctx);
    }

    void SceneManager::render(EngineContext& ctx)
    {
        currentScene->render(ctx);
    }
} // namespace engine