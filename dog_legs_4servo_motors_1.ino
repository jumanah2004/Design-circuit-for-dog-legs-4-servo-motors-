#include <Servo.h>

Servo s1, s2, s3, s4;

void setup() {
  s1.attach(3);
  s2.attach(5);
  s3.attach(6);
  s4.attach(9);

  unsigned long startTime = millis();

  while (millis() - startTime < 2000) {
    for (int pos = 0; pos <= 180; pos++) {
      s1.write(pos);
      s2.write(pos);
      s3.write(pos);
      s4.write(pos);
      delay(5);

      if (millis() - startTime >= 2000)
        break;
    }

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

  s1.write(90);
  s2.write(90);
  s3.write(90);
  s4.write(90);
}

void loop() {
}