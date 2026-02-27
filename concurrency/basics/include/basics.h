#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <future>

using namespace std::chrono_literals;

void DisplayMessage();

void basic_thread();

void increment_counter(int& counter);

void mutex_example();

void async_example();

void future_promise_example();