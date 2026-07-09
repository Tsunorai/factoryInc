#include "command/quitCommand.hpp"

#include "engine.hpp"

namespace engine
{
    void QuitCommand::execute(Engine& engine)
    {
        engine.shutdown();
    }
} // namespace engine