#include "abstract_factory_example.h"

void SamsungMobile::purpose()
{
    std::cout << "Samsung Mobile is used for calling, texting, gaming and many more!" << std::endl;
}

SamsungMobile::~SamsungMobile()
{
    std::cout << "Samsung Mobile is destroyed!" << std::endl;
}

void SamsungLaptop::purpose()
{
    std::cout << "Samsung Laptop is used for programming, gaming and many more!" << std::endl;
}

SamsungLaptop::~SamsungLaptop()
{
    std::cout << "Samsung Laptop is destroyed!" << std::endl;
}

void AppleMobile::purpose()
{
    std::cout << "Apple Mobile is used for calling, texting, gaming and many more!" << std::endl;
}

AppleMobile::~AppleMobile()
{
    std::cout << "Apple Mobile is destroyed!" << std::endl;
}

void AppleLaptop::purpose()
{
    std::cout << "Apple Laptop is used for programming, gaming and many more!" << std::endl;
}

AppleLaptop::~AppleLaptop()
{
    std::cout << "Apple Laptop is destroyed!" << std::endl;
}

std::unique_ptr<IMobile> SamsungFactory::CreateMobile()
{
    return std::make_unique<SamsungMobile>();
}

std::unique_ptr<ILaptop> SamsungFactory::CreateLaptop()
{
    return std::make_unique<SamsungLaptop>();
}

std::unique_ptr<IMobile> AppleFactory::CreateMobile()
{
    return std::make_unique<AppleMobile>();
}

std::unique_ptr<ILaptop> AppleFactory::CreateLaptop()
{
    return std::make_unique<AppleLaptop>();
}

void abstract_factory_example()
{
    std::cout << "Abstract Factory Example!" << std::endl;

    std::unique_ptr<IProductFactory> samsung_factory = std::make_unique<SamsungFactory>();
    std::unique_ptr<IMobile> samsung_mobile = samsung_factory->CreateMobile();
    std::unique_ptr<ILaptop> samsung_laptop = samsung_factory->CreateLaptop();

    samsung_mobile->purpose();
    samsung_laptop->purpose();

    std::cout << std::endl;

    std::unique_ptr<IProductFactory> apple_factory = std::make_unique<AppleFactory>();
    std::unique_ptr<IMobile> apple_mobile = apple_factory->CreateMobile();
    std::unique_ptr<ILaptop> apple_laptop = apple_factory->CreateLaptop();

    apple_mobile->purpose();
    apple_laptop->purpose();
}