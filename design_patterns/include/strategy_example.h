#include <iostream>
#include <string>
#include <memory>

class IWalkSTrategy{
    public:
        virtual void walk() = 0;
        virtual ~IWalkSTrategy() = default;
};

class NormalSituation: public IWalkSTrategy{
    public:
        void walk() override;
        ~NormalSituation() = default;
};

class DuringPregnancy: public IWalkSTrategy{
    public:
        void walk() override;
        ~DuringPregnancy() = default;
};

class Person{
    private:
        std::unique_ptr<IWalkSTrategy> m_walk_strategy;
    public:
        Person(std::unique_ptr<IWalkSTrategy> walk_strategy);
        void set_walk_strategy(std::unique_ptr<IWalkSTrategy> walk_strategy);
        void walk();
        ~Person() = default;
};

void strategy_example();