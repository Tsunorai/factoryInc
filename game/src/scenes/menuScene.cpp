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

        for (auto& button : buttons)
        {
            button.update();
        }

        return {engine::SceneAction::None};
    }

    void MenuScene::render(const engine::Renderer& renderer)
    {
        renderer.drawBackground(RED);
        for (auto& button : buttons)
        {
            renderer.drawButton(button);
        }
        // Render menu UI elements here
    }

    void MenuScene::createMenu()
    {
        // will be replaced by configuration in json or something
        engine::Button btn1{0, 0, 300, 150, BLUE, "Button"};
        buttons.push_back(btn1);
    }
} // namespace FInc