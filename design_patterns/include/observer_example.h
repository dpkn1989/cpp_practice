#include <iostream>
#include <functional>
#include <vector>

using Callback = std::function<void(int)>;

class SpeedState{
    int16_t m_speed;
    std::vector<Callback> m_subscribers;

public:
    SpeedState();
    void Subscribe(Callback cb);
    void SetSpeed(int16_t speed);
};

class SpeedDisplay{
    public:
    void operator()(int16_t speed){
        std::cout << "Current Speed: " << speed << " km/h" << std::endl;
    }
};

class SpeedAlert{
    public:
    void operator()(int16_t speed){
        if(speed > 100){
            std::cout << "Speed Alert! Slow down!" << std::endl;
        }
    }
};

void observer_example();