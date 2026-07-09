#include "scene/menuScene.hpp"

#include "command/changeSceneCommand.hpp"
#include "command/quitCommand.hpp"
#include "engineMapping.hpp"
#include "scene/gameScene.hpp"
#include "struct/button.hpp"
#include "struct/text.hpp"

#include <iostream>
#include <memory>

namespace FInc
{
    MenuScene::MenuScene(engine::EngineContext& ctx)
    {
        std::cout << "MenuScene created" << std::endl;
        createMenu(ctx);
    }

    void MenuScene::enter()
    {
        std::cout << "MenuScene::enter" << std::endl;
    }

    void MenuScene::update(engine::EngineContext& ctx)
    {
        for (auto& element : buttons)
        {
            element->update(ctx);
        }
    }

    void MenuScene::render(engine::EngineContext& ctx)
    {
        // todo have non raylib colors
        ctx.renderer.drawBackground(BLACK);
        for (const auto& button : buttons)
        {
            button->render(ctx);
        }
    }

    void MenuScene::exit()
    {
        std::cout << "MenuScene::exit" << std::endl;
    }

    void MenuScene::createMenu(engine::EngineContext& ctx)
    {
        // will be replaced by configuration in json or something

        auto playFunc = [&ctx]() {
            ctx.commands.enqueue<engine::ChangeSceneCommand>(std::make_unique<GameScene>());
        };

        // todo menu creation on replace withouth raylib reference
        Rectangle rect = {engine::getScreenWidth() / 2.0f - 150, engine::getScreenHeight() / 4.0f - 75, 300, 150};
        engine::Text label("Play");

        auto btn = std::make_unique<engine::Button>(playFunc, rect, label);
        buttons[0] = std::move(btn);

        auto settingsFunc = []() {
            std::cout << "Settings button clicked WIP" << std::endl;
        };

        // todo menu creation on replace withouth raylib reference
        Rectangle rect2 = {engine::getScreenWidth() / 2.0f - 150, engine::getScreenHeight() / 4.0f * 2.0f - 75, 300, 150};
        engine::Text label2("Settings");

        auto btn2 = std::make_unique<engine::Button>(settingsFunc, rect2, label2);
        buttons[1] = std::move(btn2);

        auto quitFunc = [&ctx]() {
            ctx.commands.enqueue<engine::QuitCommand>();
        };

        // todo menu creation on replace withouth raylib reference
        Rectangle rect3 = {engine::getScreenWidth() / 2.0f - 150, engine::getScreenHeight() / 4.0f * 3.0f - 75, 300, 150};
        engine::Text label3("Quit");

        auto btn3 = std::make_unique<engine::Button>(quitFunc, rect3, label3);
        buttons[2] = std::move(btn3);
    }
} // namespace FInc