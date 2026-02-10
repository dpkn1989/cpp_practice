#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <queue>

class Logger{
    std::thread worker;
    std::queue<std::string> messages;
    std::mutex mtx;
    std::condition_variable cv;
    bool finish;

    public:
    Logger():  finish(false)
    {
        worker = std::thread([this](){
            while(true)
            {
                std::unique_lock<std::mutex> lock(mtx);
                cv.wait(lock, [this](){ return !messages.empty() || finish;});

                while(!messages.empty()){
                    std::cout << messages.front() << std::endl;
                    messages.pop();
                }
                
                if(finish){
                    break;
                }
            }
        });
    }

    ~Logger(){
        {
            std::lock_guard<std::mutex> lock(mtx);
            finish = true;
        }
        cv.notify_one();
        worker.join();
    }

    void log(const std::string& msg)
    {
        {
            std::lock_guard<std::mutex> lock(mtx);
            messages.push(msg); 
        }
        cv.notify_one();
    }
};


int main(){

    Logger logger;
    std::vector<std::thread> threads;

    for(int i=0; i<5; i++)
    {
        threads.push_back(std::thread([&logger, i](){
            for(int j= 0; j<5; j++)
            {
                logger.log("Logging message from thread " + std::to_string(i) + " and the message number is " + std::to_string(j)
                            + " and this thread id is " + std::to_string(std::hash<std::thread::id>{}(std::this_thread::get_id())));
            }
        }));
    }

    for(auto& t: threads)
    {
        t.join();
    }

    return 0;
}