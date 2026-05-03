# RohitCore-Power

Battery and voltage monitoring library for Arduino.

Provides voltage reading, battery percentage estimation, and low battery detection.

Compatible with:
- Arduino UNO
- Arduino Nano
- ESP32

---

## ⚠️ Important

Requires a voltage divider to measure battery voltage safely.

---

## 🚀 Features

- Voltage measurement
- Battery percentage estimation
- Low battery detection
- Lightweight API

---

## 🧪 Example

```cpp
#include <RohitCore-Power.h>

RohitCorePower power;

void setup() {
  Serial.begin(115200);
  power.begin(A0, 2.0);
}

void loop() {
  Serial.println(power.getVoltage());
  Serial.println(power.getBatteryPercentage());
  delay(1000);
}
