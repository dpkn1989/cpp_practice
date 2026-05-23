#include "observer_example.h"

SpeedState::SpeedState() : m_speed(0) {}

void SpeedState::Subscribe(Callback cb)
{
    m_subscribers.push_back(cb);
}

void SpeedState::SetSpeed(int16_t speed)
{
    m_speed = speed;
    for (const auto& subscriber : m_subscribers)
    {
        subscriber(m_speed);
    }
}

void observer_example()
{
    SpeedState speedState;

    SpeedDisplay display;
    SpeedAlert alert;

    speedState.Subscribe(display);
    speedState.Subscribe(alert);

    speedState.SetSpeed(90);
    speedState.SetSpeed(120);
}