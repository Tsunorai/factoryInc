#include "game.hpp"
#include "engine.hpp"

int main ()
{
    engine::Engine engine;
    FInc::Game game;

    engine.init();
    engine.run(game);
    return 0;
}