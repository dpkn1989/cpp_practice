#include <iostream>

class IBrakeSensor{
public:
    virtual bool isBrakeApplied() = 0;
    virtual ~IBrakeSensor() = default;
    virtual void applyBrake() = 0;
    virtual void releaseBrake() = 0;
};

class RearBrakeSensor : public IBrakeSensor{
    bool brakeApplied = false;
    public:
    RearBrakeSensor() = default;
    bool isBrakeApplied() override{
        return brakeApplied;
    }
    void applyBrake() override{
        brakeApplied = true;
    }
    void releaseBrake() override{
        brakeApplied = false;
    }
};

class BrakeDecorator: public IBrakeSensor{
    IBrakeSensor* m_brakeSensor;
    public:
    BrakeDecorator(IBrakeSensor* brakeSensor): m_brakeSensor(brakeSensor){}
    bool isBrakeApplied() override{
        std::cout << "Checking brake status: " << std::endl;
        return m_brakeSensor->isBrakeApplied();
    }
    void applyBrake() override{
        std::cout << "Applying brake..." << std::endl;
        m_brakeSensor->applyBrake();
    }
    void releaseBrake() override{
        std::cout << "Releasing brake..." << std::endl;
        m_brakeSensor->releaseBrake();
    }
};

void decorator_example();
