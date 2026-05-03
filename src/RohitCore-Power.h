#ifndef RohitCore_Power_h
#define RohitCore_Power_h

#include <Arduino.h>

class RohitCorePower {
  public:
    RohitCorePower();

    // Initialize with analog pin and voltage divider factor
    void begin(int pin, float dividerFactor = 1.0);

    // Get battery voltage
    float getVoltage();

    // Estimate battery percentage (based on Li-ion range)
    int getBatteryPercentage();

    // Check if battery is below threshold
    bool isLowBattery(float threshold = 3.3);

  private:
    int _pin;
    float _divider;
};

#endif
