#pragma once

#include <string>
#include <cmath>

typedef enum { REAL,
  IMAGINARY,
  COMPLEX
} number_type; // simplify calculations by knowing number type

class Number {
  private:
    number_type number_type_;
    float magnitude_;
    float phase_; // store phase in degrees
    float real_;
    float imaginary_;
  public:
    Number();
    Number(float new_magnitude, float new_phase, number_type type);
    float get_magnitude();
    float get_phase();
    number_type get_number_type();
    void set_number_type(number_type type);
    void set_magnitude(float new_magnitude);
    void set_phase(float new_phase);

    // operator overload
    Number operator+(Number& input_num);
    Number operator-(Number& input_num);
    Number operator*(Number& input_num);
    Number operator/(Number& input_num);

};

float degree_to_radian(float degrees);
float radian_to_degree(float radians);
number_type determine_number_type(float phase);
float get_real(float phase, float magnitude);
float get_imag(float phase, float magnitude);
void print_phasor(Number& phasor);
