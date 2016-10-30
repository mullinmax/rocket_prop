#include<Wire.h>
#ifndef SENSORS
#define SENSORS
class sensors {
  public:
    sensors() {

    }
    void boot() {
      Wire.begin();
      Wire.beginTransmission(address);
      Wire.write(0x6B);  // PWR_MGMT_1 register
      Wire.write(0);     // set to zero (wakes up the MPU-6050)
      Wire.endTransmission(true);
      Serial.begin(9600);
    }
    void calibrate() {
      read_values(400);
      cacx = acx;
      cacy = acy;
      cacz = acz;
      ctmp = tmp;
      cgyx = gyx;
      cgyy = gyy;
      cgyz = gyz;
    }
    void read_values(float s) {
      Wire.beginTransmission(address);
      Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
      Wire.endTransmission(false);
      Wire.requestFrom(address, 14, true); // request a total of 14 registers
      acx = Wire.read() << 8 | Wire.read(); // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)
      acy = Wire.read() << 8 | Wire.read(); // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
      acz = Wire.read() << 8 | Wire.read(); // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
      tmp = Wire.read() << 8 | Wire.read(); // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
      gyx = Wire.read() << 8 | Wire.read(); // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
      gyy = Wire.read() << 8 | Wire.read(); // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
      gyz = Wire.read() << 8 | Wire.read(); // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)
      smooth(s);
    }
    void smooth(float s) {
      acx = (acx + pacx * s) / (s + 1);
      acy = (acy + pacy * s) / (s + 1);
      acz = (acz + pacz * s) / (s + 1);
      tmp = (tmp + ptmp * s) / (s + 1);
      gyx = (gyx + pgyx * s) / (s + 1);
      gyy = (gyy + pgyy * s) / (s + 1);
      gyz = (gyz + pgyz * s) / (s + 1);
    }
    int address = 0x68;
    float acx, acy, acz, tmp, gyx, gyy, gyz;
    float pacx, pacy, pacz, ptmp, pgyx, pgyy, pgyz;
    float cacx, cacy, cacz, ctmp, cgyx, cgyy, cgyz;
};
#endif
