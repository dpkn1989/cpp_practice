#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <queue>

std::mutex mtx;
std::condition_variable cv;
std::queue<int> dataQueue;
const int MAX_QUEUE_SIZE = 100;

void producer(){
    for(int i = 0; i < MAX_QUEUE_SIZE; i++){
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []{ return dataQueue.size() < MAX_QUEUE_SIZE; });
        dataQueue.push(i);
        lock.unlock();
        std::cout << "Produced: " << i << std::endl;
        cv.notify_one();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void consumer(){
    for(int i = 0; i < MAX_QUEUE_SIZE; i++){
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []{ return !dataQueue.empty(); });
        int value = dataQueue.front();
        dataQueue.pop();
        lock.unlock();
        std::cout << "Consumed: " << value << std::endl;
        cv.notify_one();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main(){

    std::thread prodThread(producer);
    std::thread consThread(consumer);

    prodThread.join();
    consThread.join();
    
    return 0;
}