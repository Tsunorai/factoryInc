#include "scene/sceneManager.hpp"

namespace engine
{
    void SceneManager::setStartScene(std::unique_ptr<IScene> scene)
    {
        loadScene(scene);
    }

    void SceneManager::loadScene(std::unique_ptr<IScene>& scene)
    {
        currentScene = std::move(scene);
        currentScene->enter();
    }

    void SceneManager::changeScene(std::unique_ptr<IScene> scene)
    {
        currentScene->exit();
        loadScene(scene);
    }

    void SceneManager::update(EngineContext& ctx)
    {
        currentScene->update(ctx);
    }

    void SceneManager::render(EngineContext& ctx)
    {
        currentScene->render(ctx);
    }

    std::unique_ptr<IScene> currentScene;
} // namespace engine