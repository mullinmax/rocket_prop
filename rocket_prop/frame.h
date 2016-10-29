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
    }
  private:
    props fans = props(10, 9, 6, 5);

};
#endif
