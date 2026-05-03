#include "RohitCore-Power.h"

RohitCorePower::RohitCorePower() {}

void RohitCorePower::begin(int pin, float dividerFactor) {
  _pin = pin;
  _divider = dividerFactor;
}

float RohitCorePower::getVoltage() {
  int raw = analogRead(_pin);

  // Convert ADC value to voltage (assuming 5V reference)
  float voltage = (raw / 1023.0) * 5.0;

  // Apply voltage divider correction
  return voltage * _divider;
}

int RohitCorePower::getBatteryPercentage() {
  float voltage = getVoltage();

  // Typical Li-ion battery range
  float minV = 3.0;
  float maxV = 4.2;

  int percent = ((voltage - minV) / (maxV - minV)) * 100;

  if (percent > 100) percent = 100;
  if (percent < 0) percent = 0;

  return percent;
}

bool RohitCorePower::isLowBattery(float threshold) {
  return getVoltage() < threshold;
}
