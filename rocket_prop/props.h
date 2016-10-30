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
    void boot(int t) {
      analogWrite(n_pin, start_pulse);
      //analogWrite(s_pin, start_pulse);
      //analogWrite(e_pin, start_pulse);
      //analogWrite(w_pin, start_pulse);
      delay(t);
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
      if (n_speed <= 100 && n_speed >= 0) {
        n_percent = n_speed;
        n_vel = pulse_range * n_speed / 100.0;
        n_vel += minimum_pulse;
      }
      if (s_speed <= 100 && s_speed >= 0) {
        s_percent = s_speed;
        s_vel = pulse_range * s_speed / 100.0;
        s_vel += minimum_pulse;
      }
      if (e_speed <= 100 && e_speed >= 0) {
        e_percent = e_speed;
        e_vel = pulse_range * e_speed / 100.0;
        e_vel += minimum_pulse;
      }
      if (w_speed <= 100 && w_speed >= 0) {
        w_percent = w_speed;
        w_vel = pulse_range * w_speed / 100.0;
        w_vel += minimum_pulse;
      }
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
      set_speed((n_percent + n_speed) % 101, (s_percent + s_speed) % 101, (e_percent + e_speed) % 101, (w_percent + w_speed) % 101);
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
    int minimum_pulse = 150;
    int start_pulse = 130;
    int pulse_range = maximum_pulse - minimum_pulse;
};

#endif
