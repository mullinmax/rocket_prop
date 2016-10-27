
class props {
  public:
    props(int north, int south, int east, int west) {
      n_pin = north;
      s_pin = south;
      e_pin = east;
      w_pin = west;
    }
    void boot(){
      boot(5000);
    }
    void boot(int t) {
      analogWrite(n_pin, start_pulse);
      analogWrite(s_pin, start_pulse);
      analogWrite(e_pin, start_pulse);
      analogWrite(w_pin, start_pulse);
      delay(t);
    }

    void set_speed(int vel){
       set_speed(vel, vel, vel, vel);
    }
    
    void set_speed(int n_speed, int s_speed, int e_speed, int w_speed) {
      if (n_speed <= 100 && n_speed >= 0) {
        n_vel = pulse_range * n_speed / 100.0;
        n_vel += minimum_pulse;
      }
      if (s_speed <= 100 && s_speed >= 0) {
        s_vel = pulse_range * s_speed / 100.0;
        s_vel += minimum_pulse;
      }
      if (e_speed <= 100 && e_speed >= 0) {
        e_vel = pulse_range * e_speed / 100.0;
        e_vel += minimum_pulse;
      }
      if (w_speed <= 100 && w_speed >= 0) {
        w_vel = pulse_range * w_speed / 100.0;
        w_vel += minimum_pulse;
      }
      analogWrite(n_pin, n_vel);
      analogWrite(s_pin, s_vel);
      analogWrite(e_pin, e_vel);
      analogWrite(w_pin, w_vel);
    }

  private:
    int n_pin;
    int s_pin;
    int e_pin;
    int w_pin;
    int n_vel;
    int s_vel;
    int e_vel;
    int w_vel;
    int maximum_pulse = 180;
    int minimum_pulse = 150;
    int start_pulse = 130;
    int pulse_range = maximum_pulse - minimum_pulse;
};
