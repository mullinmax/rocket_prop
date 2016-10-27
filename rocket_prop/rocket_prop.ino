#include "prop_control_functions.h"

props fans(10, 5, 6, 9);

void setup() {
  props fans(10, 5, 6, 9);
  fans.boot(5000);
}

void loop() {
  for (int i = 0 ; i <= 100; i += 1) {
    fans.set_speed(i);
    Serial.print(i);
    Serial.println();
    // wait for 30 milliseconds to see the dimming effect
    delay(60);
  }
   for (int i = 100 ; i >= 0; i -= 1) {
    fans.set_speed(i);
    Serial.print(i);
    Serial.println();
    // wait for 30 milliseconds to see the dimming effect
    delay(60);
  }
}


