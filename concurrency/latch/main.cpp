#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <queue>

#include <mutex>
#include <condition_variable>
#include <stdexcept>

class CountdownLatch {
public:
    explicit CountdownLatch(int count) : count_(count) {
        if (count < 0) {
            throw std::invalid_argument("count must be non-negative");
        }
    }

    // Decrements the count. When it reaches zero, notifies all waiting threads.
    void arrive() {
        std::unique_lock<std::mutex> lock(mutex_);
        if (count_ == 0) {
            return; // or throw, depending on desired semantics
        }

        --count_;
        if (count_ == 0) {
            cv_.notify_all();
        }
    }

    // Blocks until the count reaches zero.
    void wait() {
        std::unique_lock<std::mutex> lock(mutex_);
        cv_.wait(lock, [this]() { return count_ == 0; });
        std::cout << "Latch released, proceeding with thread id: " << std::this_thread::get_id() << "\n";
    }

    // Optional: observe current count (non-blocking)
    int get_count() const {
        std::lock_guard<std::mutex> lock(mutex_);
        return count_;
    }

private:
    mutable std::mutex mutex_;
    std::condition_variable cv_;
    int count_;
};


int main() {
    CountdownLatch latch(3);

    std::vector<std::thread> workers;
    for (int i = 0; i < 5; ++i) {
        if(i%2 == 0){
            workers.emplace_back([&latch, i]() {
            // simulate work
            std::this_thread::sleep_for(std::chrono::milliseconds(100 * (i + 1)));
            std::cout << "Worker " << i << " with thread id " << std::this_thread::get_id() << " arrived\n";
            latch.arrive();
            });
        }
        else{
            workers.emplace_back([&latch, i]() {
            // simulate work
            std::this_thread::sleep_for(std::chrono::milliseconds(100 * (i + 1)));
            std::cout << "Worker " << i << " with thread id " << std::this_thread::get_id() << " blocked\n";
            latch.wait();
        });
        }
        
    }

    //std::cout << "Main thread waiting...\n";
    //latch.wait();
    //std::cout << "All workers arrived. Proceeding.\n";

    for (auto& t : workers) {
        t.join();
    }
}
