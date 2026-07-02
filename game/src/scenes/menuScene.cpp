#include "scenes/menuScene.hpp"

#include "structs/button.hpp"
#include "engineMapping.hpp"
#include "structs/keys.hpp"
#include "scenes/gameScene.hpp"

#include <iostream>
#include <memory>

namespace FInc
{
    MenuScene::MenuScene()
    {
        std::cout << "MenuScene created" << std::endl;
        createMenu();
    }

    engine::SceneResult MenuScene::update()
    {
        if (engine::isKeyPressed(engine::KEY_ENTER))
        {
            return {engine::SceneAction::ChangeScene, std::move(std::make_unique<GameScene>())};
        }

        for (auto& element : actors)
        {
            element->update();
        }

        return {engine::SceneAction::None};
    }

    void MenuScene::render(const engine::Renderer& renderer)
    {
        renderer.drawBackground(RED);
        for (const auto& actor : actors)
        {
            actor->render(renderer);
        }
    }

    void MenuScene::createMenu()
    {
        // will be replaced by configuration in json or something
        std::unique_ptr<engine::Actor> btn = std::make_unique<engine::Button>(engine::getScreenWidth() / 2.0f - 150, engine::getScreenHeight() / 2.0f - 75, 300, 150, BLUE, "Button");
        actors.push_back(std::move(btn));
    }
} // namespace FInc