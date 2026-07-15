# Design-circuit-for-dog-legs(4-servo-motors)
---
# 🐕 4 Servo Motors Control Using Arduino

This project demonstrates how to control 4 servo motors using an Arduino Uno. The servo motors perform a Sweep movement for 2 seconds, then all motors stop and hold at 90 degrees.

---

## 🔗 Open the Project in Tinkercad

To open and run the circuit in Tinkercad, use the following link:

✨ [Visit my  Tinkard here!](https://www.tinkercad.com/things/1YqaDvzoToS-dog-legs4servo-motors)

*After opening the project, click Start Simulation to run the circuit.*

---

## 🖼️ Circuit Diagram & video

![Circuit Diagram](https://github.com/jumanah2004/Design-circuit-for-dog-legs-4-servo-motors-/blob/ad557e92e85d8b82b050a89343ffa2ce91c38a3d/dog%20legs(4servo%20motors).png)

https://github.com/user-attachments/assets/1b869a7c-ef25-4b6b-9dcd-515da866091b

[also the link of video!](https://github.com/user-attachments/assets/1b869a7c-ef25-4b6b-9dcd-515da866091b)
---

## 💻 Arduino Code

```cpp
#include <Servo.h>

Servo s1, s2, s3, s4;

void setup() {
  // Attach servo motors to Arduino PWM pins
  s1.attach(3);
  s2.attach(5);
  s3.attach(6);
  s4.attach(9);

  unsigned long startTime = millis();

  // Sweep movement for exactly 2 seconds (2000 ms)
  while (millis() - startTime < 2000) {
    // Sweep from 0 to 180 degrees
    for (int pos = 0; pos <= 180; pos++) {
      s1.write(pos);
      s2.write(pos);
      s3.write(pos);
      s4.write(pos);
      delay(5);

      // Safety check to break loop if 2 seconds have passed
      if (millis() - startTime >= 2000)
        break;
    }

    // Sweep back from 180 to 0 degrees
    for (int pos = 180; pos >= 0; pos--) {
      s1.write(pos);
      s2.write(pos);
      s3.write(pos);
      s4.write(pos);
      delay(5);

      if (millis() - startTime >= 2000)
        break;
    }
  }

  // Stop and hold all motors at 90 degrees
  s1.write(90);
  s2.write(90);
  s3.write(90);
  s4.write(90);
}

void loop() {
  // Loop is empty because the setup handles the timed movement once
}
```
----
📝 Simple Code Explanation

* Pin Connections: The code connects 4 servo motors to Arduino pins 3, 5, 6, and 9 (which are PWM-enabled pins).
* Sweep Movement: Upon startup, all four motors perform a synchronized sweep movement back and forth between 0° and 180° for exactly 2 seconds.
* Hold Position: Once the 2-second limit is reached, the active movement loop breaks, and all servo motors immediately transition to 90° and lock in that position.
* Robotic Dog Application: This sequence is designed to simulate a quick "calibration" or synchronized leg movement, ending with the robotic dog standing in a stable, neutral position.
