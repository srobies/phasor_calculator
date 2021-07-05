#include <cmath>
#include "phasor.h"

Number::Number() {
  number_type = REAL;
  magnitude = 0;
  phase = 0;
}

Number::Number(double new_magnitude, double new_phase, enum number_type) {
  number_type = REAL;
  magnitude = 0;
  phase = 0;
}
