#include <iostream>
#include <string>
#include <memory>

class Animal{
    public:
        virtual void purpose() = 0;
        virtual ~Animal() = default;
};

class Cow : public Animal{
    public:
        void purpose() override;
        ~Cow();
};

class Dog : public Animal{
    public:
        void purpose() override;
        ~Dog();
};

class AnimalFactory{
    public:
        std::unique_ptr<Animal> CreatAnimal(const std::string& animal);
};

void factory_example();