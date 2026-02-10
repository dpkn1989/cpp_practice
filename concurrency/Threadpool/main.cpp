#include <iostream>
#include <vector>
#include <thread>
#include <queue>
#include <functional>
#include <condition_variable>
#include <future>

class Threadpool{
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;
    std::mutex mtx;
    std::condition_variable cv;
    bool stop;

public:
    Threadpool(size_t count): stop(false){
        for(size_t i=0; i<count; i++)
        {
            workers.emplace_back(
                [this]{
                    while(true){
                        std::function<void()> task;
                        {
                            std::unique_lock<std::mutex> lock(mtx);
                            cv.wait(lock, [this] {return stop || !tasks.empty(); } );                        
                        
                            if(stop && tasks.empty())
                                return;
                            
                            task = tasks.front();
                            tasks.pop();
                        }
                        task();
                    }
                }
            );
        }
    }

    template<typename F, typename... Args>
    auto submit(F&& f, Args... args) -> std::future<typename std::result_of<F(Args...)>::type>
    {
        using Returntype = std::result_of<F(Args...)>::type;
        auto taskptr = std::make_shared<std::packaged_task<Returntype()>>(
            std::bind(std::forward<F>(f), std::forward<Args>(args)...)
        );
        //std::future<Returntype> result = taskptr->get_future();
        {
            std::lock_guard<std::mutex> lock(mtx);
            tasks.emplace([taskptr]{ (*taskptr)(); });
        }
        cv.notify_one();

        //return result;
    }

    ~Threadpool(){
        {
            std::lock_guard<std::mutex> lock(mtx);
            stop = true;
        }

        cv.notify_all();

        for(auto& t: workers)
            t.join();
    }
};

int main(){
    Threadpool tp(5);

    /*for(int i=0; i<10; i++){
        tp.submit([]{
            std::cout << "Task executed by thread: " << std::this_thread::get_id() << std::endl;
        });
    }*/

    auto a = tp.submit([](int x, int y){
        std::cout << "The sum of " << x << " and " << y << " is calculated." << std::endl;
        return x + y;
    }, 3,9);

    int result = a.get();

    std::cout << "Result from future is: " << result << std::endl;
}