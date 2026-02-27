#include "basics.h"

std::mutex mtx;

void DisplayMessage() {
    std::cout << "Hello from a thread!" << std::endl;
    
    int x = 5;
    while(x > 0) {
        std::cout << "DisplayMessage Thread running at count: " << x << std::endl;
        std::this_thread::sleep_for(1s);
        --x;
    }
    std::cout << "DisplayMessage Thread finished at count: " << x << std::endl;
}

void basic_thread()
{
    std::thread t1{DisplayMessage};

    int x = 9;
    while(x > 0) {
        std::cout << "Main thread running at count: " << x << std::endl;
        std::this_thread::sleep_for(1s);
        --x;
    }

    std::cout << "Number of hardware threads: " << std::thread::hardware_concurrency() << std::endl;

    if(t1.joinable()) {
        t1.join();
        std::cout << "DisplayMessage Thread joined to Main Thread." << std::endl;
    }
    std::cout << "Main Thread finished at count: " << x << std::endl;
}

void increment_counter(int& counter) {
    for(int i = 0; i < 100000; ++i) {
        std::lock_guard<std::mutex> lock(mtx);
        ++counter;
        // std::cout << "Counter incremented to: " << counter << std::endl;
    }
}

void mutex_example() {
    int counter = 0;
    std::thread t1{increment_counter, std::ref(counter)};
    std::thread t2{increment_counter, std::ref(counter)};

    t1.join();
    t2.join();

    std::cout << "Final counter value: " << counter << std::endl;
}

void async_example() {
    std::future<int> future_result = std::async(std::launch::async, [](){
        std::cout << "Async task started." << std::endl;
        std::this_thread::sleep_for(5s);
        std::cout << "Async task finished." << std::endl;
        return 50;      
    });

    std::cout << "Doing other work in main thread..." << std::endl;
    std::this_thread::sleep_for(2s);    
    std::cout << "Main thread work done, waiting for async result..." << std::endl;
    std::cout << "Async result: " << future_result.get() << std::endl;

    if(future_result.valid()) {
        std::cout << "Future is still valid." << std::endl;
        int y = future_result.get(); // This will not block as the result is already available
        std::cout << "Async result retrieved again: " << y << std::endl;
    } else {
        std::cout << "Future is no longer valid after get()." << std::endl;
    }
    
}

int give_future_result(std::promise<int>& promise_data)
{
    std::future<int> future_result = promise_data.get_future();
    std::cout << "Waiting for promise to be fulfilled..." << std::endl;
    int result = future_result.get() + 30; // This will block until the promise is fulfilled
    std::cout << "Promise fulfilled with value: " << result << std::endl;
    return result;
}

void future_promise_example()
{
    std::promise<int> promise_data;
    std::future<int> future_data = std::async(std::launch::async, give_future_result, std::ref(promise_data));
    std::this_thread::sleep_for(3s); // Simulate some work before fulfilling the promise
    std::cout << "Fulfilling promise with value 90." << std::endl;
    promise_data.set_value(90); // Fulfill the promise with a value

    future_data.wait(); // Wait for the async task to complete
    std::cout << "Future promise example completed and the value from async task is: " << future_data.get() << std::endl;
}