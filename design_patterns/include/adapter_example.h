#include <iostream>

class SupplierSpeedSensor {
    int16_t m_speedMPS;
    public:
    SupplierSpeedSensor(int16_t speedMPS) : m_speedMPS(speedMPS) {}
    void SetSpeedMPS(int16_t speedMPS) {
        m_speedMPS = speedMPS;
    }
    int16_t GetSpeedMPS() {
        return m_speedMPS;
    }
};

class ISpeedSensor{
    public:
    virtual int16_t GetSpeedKMPH() = 0;
};

class SpeedSensorAdapter : public ISpeedSensor{
    SupplierSpeedSensor* m_supplierSensor;
    public:
    SpeedSensorAdapter(SupplierSpeedSensor* supplierSensor) : m_supplierSensor(supplierSensor) {}
    int16_t GetSpeedKMPH() override {
        return static_cast<int16_t>(m_supplierSensor->GetSpeedMPS() * 3.6);
    }
};

void adapter_example();