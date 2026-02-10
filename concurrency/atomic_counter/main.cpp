#include <iostream>
#include <atomic>
#include <thread>
#include <vector>

class Counter{
    std::atomic<uint64_t> count;
public:
    Counter() : count(0) {}
    void increment(uint64_t value){
        count.fetch_add(value, std::memory_order_relaxed);
    }

    uint64_t get() const{
        return count.load(std::memory_order_relaxed);
    }
};

int main(){
    std::vector<std::thread> threads;
    Counter counter;
    constexpr int num_threads = 10;
    constexpr int num_increments = 100000;

    threads.reserve(num_threads);

    for(int i=0; i<num_threads; i++){
        threads.emplace_back([&](){
            for(int j=0; j<num_increments; j++)
            counter.increment(1);
        });
    }

    for(auto& t : threads){
        t.join();
    }

    std::cout << "Final counter value is: " << counter.get() << " and the expected value is " << (num_threads * num_increments) << std::endl;
    return 0;
    
}