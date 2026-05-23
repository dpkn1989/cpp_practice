#include "decorator_example.h"

void decorator_example(){
    std::cout << "Decorator Example: " << std::endl;
    RearBrakeSensor rearBrakeSensor;
    BrakeDecorator brakeDecorator(&rearBrakeSensor);

    brakeDecorator.applyBrake();
    std::cout << "Is brake applied? " << brakeDecorator.isBrakeApplied() << std::endl;

    brakeDecorator.releaseBrake();
    std::cout << "Is brake applied? " << brakeDecorator.isBrakeApplied() << std::endl;
}