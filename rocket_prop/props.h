#ifndef PROPS
#define PROPS

class props {
  public:
    //Initializes all the pins
    props(int north, int south, int east, int west) {
      n_pin = north;
      s_pin = south;
      e_pin = east;
      w_pin = west;
    }

    void set_pins(int north, int south, int east, int west) {
      n_pin = north;
      s_pin = south;
      e_pin = east;
      w_pin = west;
    }

    //starts fans spinning
    void boot() {
      analogWrite(n_pin, start_pulse);
      analogWrite(s_pin, start_pulse);
      analogWrite(e_pin, start_pulse);
      analogWrite(w_pin, start_pulse);
      delay(2000);
      for (int i = start_pulse; i <= minimum_pulse; i++) {
        analogWrite(n_pin, i);
        analogWrite(s_pin, i);
        analogWrite(e_pin, i);
        analogWrite(w_pin, i);
        delay(40);
      }
    }

    //completely stops all fans
    void halt_all() {
      analogWrite(n_pin, 0);
      analogWrite(s_pin, 0);
      analogWrite(e_pin, 0);
      analogWrite(w_pin, 0);
    }

    //sets the speed on a scale of 0 to 100 of each individual fan
    void set_speed(int n_speed, int s_speed, int e_speed, int w_speed) {
      int tmp_n_vel;
      int tmp_s_vel;
      int tmp_e_vel;
      int tmp_w_vel;
      if (n_speed <= 100 && n_speed >= 0) {
        n_percent = n_speed;
        tmp_n_vel = pulse_range * n_speed / 100.0;
      }else if(n_speed > 100){
        tmp_n_vel = pulse_range;
      }
      if (s_speed <= 100 && s_speed >= 0) {
        s_percent = s_speed;
        tmp_s_vel = pulse_range * s_speed / 100.0;
      }else if(s_speed > 100){
        tmp_s_vel = pulse_range;
      }
      if (e_speed <= 100 && e_speed >= 0) {
        e_percent = e_speed;
        tmp_e_vel = pulse_range * e_speed / 100.0;
      }else if(w_speed > 100){
        tmp_e_vel = pulse_range;
      }
      if (w_speed <= 100 && w_speed >= 0) {
        w_percent = w_speed;
        tmp_w_vel = pulse_range * w_speed / 100.0;
      }else if(w_speed > 100){
        tmp_w_vel = pulse_range;
      }
      tmp_n_vel += minimum_pulse;
      tmp_s_vel += minimum_pulse;
      tmp_e_vel += minimum_pulse;
      tmp_w_vel += minimum_pulse;
      int s = 4;
      n_vel = (n_vel*4+tmp_n_vel)/(s+1);
      s_vel = (s_vel*4+tmp_s_vel)/(s+1);
      e_vel = (e_vel*4+tmp_e_vel)/(s+1);
      w_vel = (w_vel*4+tmp_w_vel)/(s+1);
      analogWrite(n_pin, n_vel);
      analogWrite(s_pin, s_vel);
      analogWrite(e_pin, e_vel);
      analogWrite(w_pin, w_vel);
    }
    //set all fans to the same speed
    void set_speed(int vel) {
      set_speed(vel, vel, vel, vel);
    }
    //increments the current speed of the fans
    void add_speed(int n_speed, int s_speed, int e_speed, int w_speed) {
      set_speed((n_percent + n_speed), (s_percent + s_speed), (e_percent + e_speed), (w_percent + w_speed));
    }

  private:
    int n_pin = 0;
    int s_pin = 0;
    int e_pin = 0;
    int w_pin = 0;

    int n_vel = 0;
    int s_vel = 0;
    int e_vel = 0;
    int w_vel = 0;

    int n_percent = 0;
    int s_percent = 0;
    int e_percent = 0;
    int w_percent = 0;

    int maximum_pulse = 180;
    int minimum_pulse = 155;
    int start_pulse = 130;
    int pulse_range = maximum_pulse - minimum_pulse;
};

#endif
