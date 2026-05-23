#include <iostream>
#include <string>
#include <memory>

class IMobile{
    public:
        virtual void purpose() = 0;
        virtual ~IMobile() = default;
};

class ILaptop{
    public:
        virtual void purpose() = 0;
        virtual ~ILaptop() = default;
};

class SamsungMobile : public IMobile{
    public:
        void purpose() override;
        ~SamsungMobile();
};

class SamsungLaptop : public ILaptop{
    public:
        void purpose() override;
        ~SamsungLaptop();
};

class AppleMobile : public IMobile{
    public:
        void purpose() override;
        ~AppleMobile();
};

class AppleLaptop : public ILaptop{
    public:
        void purpose() override;
        ~AppleLaptop();
};

class IProductFactory{
    public:
        virtual std::unique_ptr<IMobile> CreateMobile() = 0;
        virtual std::unique_ptr<ILaptop> CreateLaptop() = 0;
        virtual ~IProductFactory() = default;
};

class SamsungFactory : public IProductFactory{
    public:
        std::unique_ptr<IMobile> CreateMobile() override;
        std::unique_ptr<ILaptop> CreateLaptop() override;
        ~SamsungFactory() = default;
};

class AppleFactory : public IProductFactory{
    public:
        std::unique_ptr<IMobile> CreateMobile() override;
        std::unique_ptr<ILaptop> CreateLaptop() override;
        ~AppleFactory() = default;
};

void abstract_factory_example();