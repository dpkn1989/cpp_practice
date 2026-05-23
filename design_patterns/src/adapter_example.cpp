#include "adapter_example.h"

void adapter_example()
{
    SupplierSpeedSensor supplierSensor(30); // Speed in MPS
    SpeedSensorAdapter adapter(&supplierSensor);

    std::cout << "Current Speed: " << adapter.GetSpeedKMPH() << " km/h" << std::endl;

    supplierSensor.SetSpeedMPS(50);  // Update speed in MPS
    std::cout << "Updated Speed: " << adapter.GetSpeedKMPH() << " km/h" << std::endl;
}