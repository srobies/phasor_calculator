#include <cmath>
#include <iostream>
#include "phasor.h"

float degree_to_radian(float degrees) {
  return degrees*(M_PI/180);
}

float radian_to_degree(float radians) {
  return radians*(180/M_PI);
}

Number::Number() {
  number_type_ = REAL;
  magnitude_ = 0;
  phase_ = 0;
}

Number::Number(float new_magnitude, float new_phase, number_type type) {
  number_type_ = type;
  magnitude_ = new_magnitude;
  phase_ = new_phase; 
}

float Number::get_magnitude() {
  return magnitude_;
}

float Number::get_phase() {
  return phase_;
}

void Number::set_magnitude(float new_magnitude) {
  magnitude_ = new_magnitude;
}

void Number::set_phase(float new_phase) {
  phase_ = new_phase;
}

Number Number::operator+(Number& input_num) {
  float magnitude_1 = get_magnitude();
  float phase_1 = get_phase();
  float magnitude_2 = input_num.get_magnitude();
  float phase_2 = input_num.get_phase();

  float real_part_1 = magnitude_1 * std::cos(degree_to_radian(phase_1));
  float imag_part_1 = magnitude_1 * std::sin(degree_to_radian(phase_1));
  float real_part_2 = magnitude_2 * std::cos(degree_to_radian(phase_2));
  float imag_part_2 = magnitude_2 * std::sin(degree_to_radian(phase_2));

  float new_magnitude = std::sqrt(pow(real_part_1+real_part_2,2) + pow(imag_part_1+imag_part_2,2));
  float new_phase = std::atan((imag_part_1+imag_part_2)/(real_part_1+real_part_2));

  set_magnitude(new_magnitude);
  set_phase(radian_to_degree(new_phase));
  return *this;
}

Number Number::operator-(Number& input_num) {
  float magnitude_1 = get_magnitude();
  float phase_1 = get_phase();
  float magnitude_2 = input_num.get_magnitude();
  float phase_2 = input_num.get_phase();

  float real_part_1 = magnitude_1 * std::cos(degree_to_radian(phase_1));
  float imag_part_1 = magnitude_1 * std::sin(degree_to_radian(phase_1));
  float real_part_2 = magnitude_2 * std::cos(degree_to_radian(phase_2));
  float imag_part_2 = magnitude_2 * std::sin(degree_to_radian(phase_2));

  float new_magnitude = std::sqrt(pow(real_part_1-real_part_2,2) + pow(imag_part_1-imag_part_2,2));
  float new_phase = std::atan((imag_part_1-imag_part_2)/(real_part_1-real_part_2)); // outputs radians

  set_magnitude(new_magnitude);
  set_phase(radian_to_degree(new_phase));
  return *this;
}

Number Number::operator*(Number& input_num) {
  float magnitude_1 = get_magnitude();
  float magnitude_2 = input_num.get_magnitude();
  float phase_1 = get_phase();
  float phase_2 = input_num.get_phase();

  set_magnitude(magnitude_1 * magnitude_2);
  set_phase(phase_1 + phase_2);
  return *this;
}

Number Number::operator/(Number& input_num) {
  float magnitude_1 = get_magnitude();
  float magnitude_2 = input_num.get_magnitude();
  float phase_1 = get_phase();
  float phase_2 = input_num.get_phase();

  set_magnitude(magnitude_1 / magnitude_2);
  set_phase(phase_1 - phase_2);
  return *this;
}

float get_real(float phase, float magnitude) { // phase in degrees
  float radian_phase = degree_to_radian(phase);
  return magnitude * std::cos(radian_phase);
}

float get_imag(float phase, float magnitude) { // phase in degrees
  float radian_phase = degree_to_radian(phase);
  return magnitude * std::sin(radian_phase);
}

void print_phasor(Number& phasor) {
  std::cout.precision(3);
  const char *angle_char = u8"\u2220";
  std::cout << phasor.get_magnitude() << angle_char << phasor.get_phase();
}
