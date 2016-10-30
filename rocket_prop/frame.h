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
    void boot(int t) {
      fans.boot(t);
      sensor.boot();
    }

    void control() {
      read_sensors();
      if(sensor.acz < -10){
        fans.set_speed(100, 0, 0, 0);
      }else{
        fans.set_speed(10, 0, 0, 0);
      }
      
    }
    void read_sensors() {
      sensor.read_values();
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
    props fans = props(10, 9, 6, 5);
    sensors sensor;

};
#endif
