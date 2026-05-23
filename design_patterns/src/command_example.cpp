#include "command_example.h"

void command_example()
{
    CommandInvoker invoker;
    
    invoker.addCommand(std::make_unique<WriteDID>());
    invoker.addCommand(std::make_unique<ReadDID>());

    std::cout << "Executing Commands:" << std::endl;
    invoker.executeCommands();
}