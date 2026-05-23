#include <iostream>
#include <string>
#include <memory>

class StateManager;

class IState{
    public:
        virtual ~IState() = default;
        virtual void HandleIgnition(StateManager& manager, bool ignitionOn) = 0;
        virtual const std::string& getName() const = 0;
};

class OffState : public IState{
    public:
        void HandleIgnition(StateManager& manager, bool ignitionOn) override;
        const std::string& getName() const override;
};

class OnState : public IState{
    public:
        void HandleIgnition(StateManager& manager, bool ignitionOn) override;
        const std::string& getName() const override;
};

class StateManager{
    private:
        std::unique_ptr<IState> currentState;
    public:
        StateManager() : currentState(std::make_unique<OffState>()) {}
        void SetState(std::unique_ptr<IState> newState);
        void HandleIgnition(bool ignitionOn);
        std::unique_ptr<IState>& GetCurrentState();
};

void state_example();