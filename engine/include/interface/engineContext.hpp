#pragma once

#include "command/commandQueue.hpp"
#include "event/eventBus.hpp"
#include "input/input.hpp"
#include "render/render.hpp"
#include "scene/sceneManager.hpp"

namespace engine
{
    struct EngineContext
    {
        EngineContext(
            Input& input,
            CommandQueue& commands,
            EventBus& events,
            SceneManager& scenes,
            Renderer& renderer,
            float deltaTime)
            : input(input),
              commands(commands),
              events(events),
              scenes(scenes),
              renderer(renderer),
              deltaTime(deltaTime)
        {
        }
        
        Input& input;

        CommandQueue& commands;

        EventBus& events;

        SceneManager& scenes;

        Renderer& renderer;

        float deltaTime;
    };
} // namespace engine