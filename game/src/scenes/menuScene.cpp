#include "scenes/menuScene.hpp"

#include "engineMapping.hpp"
#include "scenes/gameScene.hpp"
#include "structs/button.hpp"
#include "structs/text.hpp"

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
        for (auto& element : actors)
        {
            element->update();
        }

        return std::move(sceneResult);
    }

    void MenuScene::render(const engine::Renderer& renderer)
    {
        // todo have non raylib colors
        renderer.drawBackground(BLACK);
        for (const auto& actor : actors)
        {
            actor->render(renderer);
        }
    }

    void MenuScene::createMenu()
    {
        // will be replaced by configuration in json or something

        auto playFunc = [this]() {
            sceneResult = {engine::SceneAction::ChangeScene, std::make_unique<GameScene>()};
        };

        // todo menu creation on replace withouth raylib reference
        Rectangle rect = {engine::getScreenWidth() / 2.0f - 150, engine::getScreenHeight() / 4.0f - 75, 300, 150};
        engine::Text label("Play");

        auto btn = std::make_unique<engine::Button>(playFunc, rect, label);
        actors.push_back(std::move(btn));

        auto settingsFunc = []() {
            std::cout << "Settings button clicked WIP" << std::endl;
        };

        // todo menu creation on replace withouth raylib reference
        Rectangle rect2 = {engine::getScreenWidth() / 2.0f - 150, engine::getScreenHeight() / 4.0f * 2.0f - 75, 300, 150};
        engine::Text label2("Settings");

        auto btn2 = std::make_unique<engine::Button>(settingsFunc, rect2, label2);
        actors.push_back(std::move(btn2));

        auto quitFunc = [this]() {
            sceneResult = {engine::SceneAction::Quit};
        };

        // todo menu creation on replace withouth raylib reference
        Rectangle rect3 = {engine::getScreenWidth() / 2.0f - 150, engine::getScreenHeight() / 4.0f * 3.0f - 75, 300, 150};
        engine::Text label3("Quit");

        auto btn3 = std::make_unique<engine::Button>(quitFunc, rect3, label3);
        actors.push_back(std::move(btn3));
    }
} // namespace FInc