#include "strategy_example.h"

void NormalSituation::walk()
{
    std::cout << "I am normal. Walking normally." << std::endl;
}

void DuringPregnancy::walk()
{
    std::cout << "I am pregnant. Walking carefully." << std::endl;
}

Person::Person(std::unique_ptr<IWalkSTrategy> walk_strategy)
    : m_walk_strategy(std::move(walk_strategy))
{
}

void Person::set_walk_strategy(std::unique_ptr<IWalkSTrategy> walk_strategy)
{
    m_walk_strategy = std::move(walk_strategy);
}

void Person::walk()
{
    m_walk_strategy->walk();
}

void strategy_example()
{
    std::cout << "Strategy Design Pattern Example:" << std::endl;

    Person person(std::make_unique<NormalSituation>());
    person.walk();

    person.set_walk_strategy(std::make_unique<DuringPregnancy>());
    person.walk();
}