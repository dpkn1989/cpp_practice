#include "basics.h"

int main() {
    std::cout << "Jai Sri Ram!" << std::endl;
    
    basic_thread();
    mutex_example();
    async_example();
    future_promise_example();

    return 0;
}