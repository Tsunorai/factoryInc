#include "commands/commandQueue.hpp"
#include "commands/command.hpp"

namespace engine
{
    void CommandQueue::push(engine::EngineCommand command)
    {
        commands.push_back(command);
    }

    std::vector<engine::EngineCommand> CommandQueue::consume()
    {
        auto result = std::move(commands);
        commands.clear();
        return result;
    }
} // namespace engine