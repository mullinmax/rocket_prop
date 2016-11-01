#include "props.h"
#include "sensors.h"
#ifndef FRAME
#define FRAME
class frame {
  public:
    frame() {

    }
    void halt_all() {
      fans.halt_all();
    }
    void boot() {
      fans.boot();
      sensor.boot();
    }
    void test() {
      fans.set_speed(50, 50, 50, 50);
    }

    void control() {
      read_sensors();
      int tol = 100;
      if (sensor.gyy + tol < 0) {
        if (sensor.gyy < 0) {
          fans.set_speed(50, 1, 50, 1);
        } else {
          fans.set_speed(50, 1, 1, 1);
        }
      } else if (sensor.gyy - tol > 0) {
        if (sensor.gyy < 0) {
          fans.set_speed(1, 50, 1, 50);
        } else {
          fans.set_speed(1, 50, 50, 1);
        }
      }
    }
    
    void read_sensors() {
      sensor.read_values(400);
      sensor.smooth(400);
      Serial.print("AcX = "); Serial.print(sensor.acx);
      Serial.print(" | AcY = "); Serial.print(sensor.acy);
      Serial.print(" | AcZ = "); Serial.print(sensor.acz);
      Serial.print(" | Tmp = "); Serial.print(sensor.tmp / 340.00 + 36.53); //equation for temperature in degrees C from datasheet
      Serial.print(" | GyX = "); Serial.print(sensor.gyx);
      Serial.print(" | GyY = "); Serial.print(sensor.gyy);
      Serial.print(" | GyZ = "); Serial.println(sensor.gyz);
    }
  private:
    props fans = props(10, 6, 9, 5);
    sensors sensor;

};
#endif
