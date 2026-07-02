#include <raylib.h>

namespace engine
{
    int getScreenHeight()
    {
        return GetScreenHeight();
    }

    int getScreenWidth()
    {
        return GetScreenWidth();
    }

    bool isKeyPressed(int key)
    {
        return IsKeyPressed(key);
    }
}