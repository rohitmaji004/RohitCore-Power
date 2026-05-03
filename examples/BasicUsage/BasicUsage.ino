#include <RohitCore-Power.h>

RohitCorePower power;

void setup() {
  Serial.begin(115200);

  // Initialize power monitoring
  // A0 = analog pin
  // 2.0 = voltage divider factor (for equal resistors like 10k + 10k)
  power.begin(A0, 2.0);

  Serial.println("RohitCore-Power Example Started");
}

void loop() {
  float voltage = power.getVoltage();
  int battery = power.getBatteryPercentage();

  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.println(" V");

  Serial.print("Battery: ");
  Serial.print(battery);
  Serial.println(" %");

  if (power.isLowBattery()) {
    Serial.println("⚠️ LOW BATTERY WARNING!");
  }

  Serial.println("----------------------");

  delay(1000);
}
