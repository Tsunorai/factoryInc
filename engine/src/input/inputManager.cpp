#include "input/inputManager.hpp"

#include "input/inputState.hpp"

#include <raylib.h>

namespace engine
{
    InputState InputManager::pollInput()
    {
        InputState input;

        pollMouseInput(input);
        pollKeyboardInput(input);

        return input;
    }

    void InputManager::pollMouseInput(InputState& input)
    {
        input.mouse.mousePosition = GetMousePosition();
        input.mouse.mouseDown = IsMouseButtonDown(MOUSE_BUTTON_LEFT);
        input.mouse.mousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
    }

    void InputManager::pollKeyboardInput(InputState& input)
    {
        input.key.enter = IsKeyPressed(KEY_ENTER);
    }

} // namespace engine