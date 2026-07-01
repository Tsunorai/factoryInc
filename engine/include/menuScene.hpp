#pragma once

#include <scene.hpp>

namespace engine
{
    class MenuScene : public Scene
    {
    public:
        SceneResult update() override;
        void render(const Renderer& renderer) override;

    private:
        // some ui elements list
    };
} // namespace engine