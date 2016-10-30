#include "frame.h"

frame rocket;

void setup() {
  delay(5000);
  rocket.boot(1000);
//  rocket.control();
//  delay(10000);
//  rocket.halt_all();
}

void loop() {

    rocket.control();
//  rocket.control();
//  //rocket.sense
//  }else{
//  rocket.halt_all();
//  }
}


