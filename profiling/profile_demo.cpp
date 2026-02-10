#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <fstream>
#include <chrono>

constexpr int NUM_THREADS = 4;
constexpr int ITERATIONS  = 50'000'000;

std::mutex file_mutex;
int shared_counter = 0;   // Intentional data race

void cpu_and_memory_task(int thread_id) {
    // Large container → heap usage
    std::vector<int> data;
    data.reserve(5'000'000);

    for (int i = 0; i < ITERATIONS / NUM_THREADS; ++i) {
        data.push_back(i * thread_id);

        // CPU-heavy loop
        if (i % 1'000'000 == 0) {
            for (volatile int j = 0; j < 10'000; ++j) {
                // Busy work
            }
        }

        // Intentional race
        shared_counter++;
    }

    // File I/O with contention
    std::lock_guard<std::mutex> lock(file_mutex);
    std::ofstream file("output.txt", std::ios::app);
    file << "Thread " << thread_id << " done\n";
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();

    std::vector<std::thread> threads;
    for (int i = 0; i < NUM_THREADS; ++i) {
        threads.emplace_back(cpu_and_memory_task, i);
    }

    for (auto& t : threads) {
        t.join();
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Final counter: " << shared_counter << "\n";
    std::cout << "Elapsed time: "
              << std::chrono::duration<double>(end - start).count()
              << " seconds\n";
}
