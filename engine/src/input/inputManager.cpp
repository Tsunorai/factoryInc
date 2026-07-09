#include "input/inputManager.hpp"

#include "input/input.hpp"

#include <raylib.h>

namespace engine
{
    Input InputManager::pollInput()
    {
        Input input{};
        pollMouseInput(input);
        pollKeyboardInput(input);
        return input;
    }
    void InputManager::pollMouseInput(Input& input)
    {
        input.mouse.mousePosition = GetMousePosition();
        input.mouse.mouseDown = IsMouseButtonDown(MOUSE_BUTTON_LEFT);
        input.mouse.mousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
    }
    void InputManager::pollKeyboardInput(Input& input)
    {
        input.key.enter = IsKeyPressed(KEY_ENTER);
        input.key.w = IsKeyPressed(KEY_W);
        input.key.a = IsKeyPressed(KEY_A);
        input.key.s = IsKeyPressed(KEY_S);
        input.key.d = IsKeyPressed(KEY_D);
    }

} // namespace engine