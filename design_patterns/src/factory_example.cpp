#include "factory_example.h"

void Cow::purpose()
{
    std::cout << "Cow gives us milk!" << std::endl;
}

Cow::~Cow()
{
    std::cout << "Cow destroyed!" << std::endl;
}

void Dog::purpose()
{
    std::cout << "Dog protects us from thieves!" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog destroyed!" << std::endl;
}

std::unique_ptr<Animal> AnimalFactory::CreatAnimal(const std::string& animal)
{
    if(animal == "Cow")
        return std::make_unique<Cow>();
    else if(animal == "Dog")
        return std::make_unique<Dog>();
    else
        return nullptr;
}

void factory_example()
{
    AnimalFactory factory;
    std::unique_ptr<Animal> cow = factory.CreatAnimal("Cow");
    std::unique_ptr<Animal> dog = factory.CreatAnimal("Dog");
    std::unique_ptr<Animal> unknown = factory.CreatAnimal("Unknown");

    if(cow)
        cow->purpose();
    if(dog)
        dog->purpose();

    if(unknown)
        unknown->purpose();
    else
        std::cout << "Unknown animal type!" << std::endl;
}