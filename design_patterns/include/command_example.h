#include <iostream>
#include <queue>
#include <memory>

class ICommand{
    public:
        virtual void execute() = 0;
        virtual ~ICommand() = default;
};

class ReadDID : public ICommand{
    public:
        void execute() override{
            std::cout << "Reading DID..." << std::endl;
        }
};

class WriteDID : public ICommand{
    public:
        void execute() override{
            std::cout << "Writing DID..." << std::endl;
        }
};

class CommandInvoker{
    std::queue<std::unique_ptr<ICommand>> commandQueue;
    public:
        void addCommand(std::unique_ptr<ICommand> cmd){
            commandQueue.push(std::move(cmd));
        }
        void executeCommands(){
            while(!commandQueue.empty()){
                commandQueue.front()->execute();
                commandQueue.pop();
            }
        }   
};

void command_example();