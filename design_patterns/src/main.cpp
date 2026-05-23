#include "singleton_example.h"
#include "factory_example.h"
#include "abstract_factory_example.h"
#include "strategy_example.h"
#include "state_example.h"
#include "observer_example.h"
#include "adapter_example.h"
#include "decorator_example.h"
#include "command_example.h"

int main()
{
    std::cout << "Jai Sri Ram!" << std::endl;

    singleton_example();
    std::cout << std::endl;
    factory_example();
    std::cout << std::endl;
    abstract_factory_example();
    std::cout << std::endl;
    strategy_example();
    std::cout << std::endl;
    state_example();
    std::cout << std::endl;
    observer_example();
    std::cout << std::endl;
    adapter_example();
    std::cout << std::endl;
    decorator_example();
    std::cout << std::endl;
    command_example();

    return 0;
}