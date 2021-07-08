#include <cmath>
#include <string>
#include "phasor.h"

double degree_to_radians(double degrees) {
  return degrees*(3.1415/180); // FIX: figure out what the library is for pi
}

double radian_to_degree(double radians) {
  return radians*(180/3.1415); // FIX: figure out what the library is for pi
}

enum number_type determine_number_type(double phase) {
  if(phase < 0.001 || abs(phase)-180 < 0.001) {
    return REAL;
  }
  else if(phase-90 < 0.001 || fmod(phase+90,360) < 0.001) {
    return IMAGINARY;
  }
  else {
    return COMPLEX;
  }
}

Number::Number() {
  number_type_ = REAL;
  magnitude_ = 0;
  phase_ = 0;
}

Number::Number(double new_magnitude, double new_phase, enum number_type type) {
  number_type_ = type;
  magnitude_ = new_magnitude;
  phase_ = new_phase;
}

double Number::get_magnitude() {
  return magnitude_;
}

double Number::get_phase() {
  return phase_;
}

enum number_type Number::get_number_type() {
  return number_type_;
}

void Number::set_number_type(enum number_type type) {
  number_type_ = type;
}

void Number::set_magnitude(double new_magnitude) {
  magnitude_ = new_magnitude;
}

void Number::set_phase(double new_phase) {
  phase_ = new_phase;
}

Number Number::operator+(Number& input_num) {
  enum number_type num_type_1 = get_number_type();
  double real_component_1 = 0;
  double imag_component_1 = 0;
  if(num_type_1 == REAL) {
    real_component_1 = get_magnitude();
    imag_component_1 = 0;
  }
  else if(num_type_1 == IMAGINARY) {
    imag_component_1 = get_magnitude();
    real_component_1 = 0;
  }
  else {
    real_component_1 = get_magnitude() * cos(degree_to_radian(get_phase()));
    imag_component_1 = get_magnitude() * sin(degree_to_radian(get_phase()));
  }

  enum number_type num_type_2 = input_num.get_number_type();
  double real_component_2 = 0;
  double imag_component_2 = 0;
  if(num_type_2 == REAL) {
    real_component_2 = input_num.get_magnitude();
    imag_component_2 = 0;
  }
  else if(num_type_2 == IMAGINARY) {
    imag_component_2 = input_num.get_magnitude();
    real_component_2 = 0;
  }
  else {
    real_component_2 = input_num.get_magnitude() * cos(degree_to_radian(input_num.get_phase()));
    imag_component_2 = input_num.get_magnitude() * sin(degree_to_radian(input_num.get_phase()));
  }
  
  double final_real = real_component_1 + real_component_2;
  double final_imag = imag_component_1 + imag_component_2;

  double final_magnitude = sqrt(pow(final_real,2) + pow(final_imag,2));
  double final_phase = radian_to_degree(tan(final_imag/final_real));

  if(final_real < 0) { // account for principle values not lining up with actual
    final_phase += 180;
    fmod(final_phase, 360);
  }

  set_magnitude(final_magnitude);
  set_phase(final_phase);
  if(final_phase < 0.001 || abs(final_phase)-180 < 0.001) {
    set_number_type(REAL);
  }
  else if(final_phase-90 < 0.001 || fmod(final_phase+90,360) < 0.001) {
    set_number_type(IMAGINARY);
  }
  else {
    set_number_type(COMPLEX);
  }

  return *this;
}

Number Number::operator-(Number& input_num) {
  return *this;
}

Number Number::operator*(Number& input_num) {
  return *this;
}

Number Number::operator/(Number& input_num) {
  return *this;
}
