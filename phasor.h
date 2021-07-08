#pragma once

#include <string>
#include <cmath>
using namespace std;

enum number_type { REAL=0, IMAGINARY=1, COMPLEX=2 }; // simplify calculations by knowing number type

class Number {
  private:
    enum number_type number_type_;
    double magnitude_;
    double phase_; // store phase in degrees
  public:
    Number();
    Number(double new_magnitude, double new_phase, enum number_type REAL);
    double get_magnitude();
    double get_phase();
    enum number_type get_number_type();
    void set_number_type(enum number_type type);
    void set_magnitude(double new_magnitude);
    void set_phase(double new_phase);

    // operator overload
    Number operator+(Number& input_num);
    Number operator-(Number& input_num);
    Number operator*(Number& input_num);
    Number operator/(Number& input_num);

    string to_string();
};

double degree_to_radian(double degrees);
double radian_to_degree(double radians);
enum number_type determine_number_type(double phase);
