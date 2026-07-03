#include "scenes/menuScene.hpp"

#include "structs/button.hpp"
#include "structs/text.hpp"
#include "engineMapping.hpp"
#include "structs/keys.hpp"
#include "scenes/gameScene.hpp"

#include <functional>
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

        std::function<void()> func = []() {
            std::cout << "Button clicked!" << std::endl;
        };

        // todo menu creation on replace withouth raylib reference
        Rectangle rect = {engine::getScreenWidth() / 2.0f - 150, engine::getScreenHeight() / 2.0f - 75, 300, 150};
        engine::Text label = {"Play", 30, GetFontDefault(), 1.0f, WHITE};

        std::unique_ptr<engine::Actor> btn = std::make_unique<engine::Button>(func, rect, BLUE, label);
        actors.push_back(std::move(btn));
    }
} // namespace FInc