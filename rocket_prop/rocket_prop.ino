#include "frame.h"

frame rocket;

void setup() {
  delay(5000);
  rocket.boot(2000);
  //rocket.test();
  delay(2000);
}

void loop() {
  rocket.control();
  if (millis() < 35000) {
    while (true) {
      rocket.halt_all();
    }
  }
  delay(40);
}


