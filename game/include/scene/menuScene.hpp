#pragma once

#include "scene/iScene.hpp"

#include "interface/engineContext.hpp"
#include "struct/button.hpp"

#include <array>
#include <memory>

namespace FInc
{
    class MenuScene : public engine::IScene
    {
    public:
        MenuScene(engine::EngineContext&);
        void update(engine::EngineContext&) override;
        void render(engine::EngineContext&) override;
        void exit() override;
        void enter() override;

    private:
        void createMenu(engine::EngineContext&);

    private:
        std::array<std::unique_ptr<engine::Button>, 3> buttons{};
    };
} // namespace FInc