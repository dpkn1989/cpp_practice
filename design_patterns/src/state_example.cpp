#include "state_example.h"

void OffState::HandleIgnition(StateManager& manager, bool ignitionOn) {
    if (ignitionOn) {
        std::cout << "Turning on the car." << std::endl;
        manager.SetState(std::make_unique<OnState>());
    } else {
        std::cout << "Car is already off." << std::endl;
    }
}

const std::string& OffState::getName() const {
    static const std::string name = "OffState";
    return name;
}

const std::string& OnState::getName() const {
    static const std::string name = "OnState";
    return name;
}

void OnState::HandleIgnition(StateManager& manager, bool ignitionOn) {
    if (!ignitionOn) {
        std::cout << "Turning off the car." << std::endl;
        manager.SetState(std::make_unique<OffState>());
    } else {
        std::cout << "Car is already on." << std::endl;
    }
}

void StateManager::SetState(std::unique_ptr<IState> newState) {
    currentState = std::move(newState);
}
        
void StateManager::HandleIgnition(bool ignitionOn) {
    currentState->HandleIgnition(*this, ignitionOn);
}

std::unique_ptr<IState>& StateManager::GetCurrentState() 
{ 
    return currentState; 
}

void state_example()
{
    StateManager manager;
    manager.HandleIgnition(true);  // Turn on the car
    std::cout << "Current state: " << manager.GetCurrentState()->getName() << std::endl;
    manager.HandleIgnition(false); // Turn off the car
    std::cout << "Current state: " << manager.GetCurrentState()->getName() << std::endl;
    manager.HandleIgnition(false); // Try to turn off again
    std::cout << "Current state: " << manager.GetCurrentState()->getName() << std::endl;
    manager.HandleIgnition(true);  // Turn on the car again
    std::cout << "Current state: " << manager.GetCurrentState()->getName() << std::endl;
}