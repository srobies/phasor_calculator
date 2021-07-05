#pragma once

#include <string>
using namespace std;

enum number_type { REAL=0, IMAGINARY=1, COMPLEX=2 };

class Number {
  private:
    int number_type;
    double magnitude;
    double phase;
  public:
    Number();
    Number(double new_magnitude, double new_phase, enum number_type REAL);
    double get_magnitude() const;
    double get_phase() const;
    int get_number_type() const;
    void set_number_type();
    void set_magnitude();
    void set_phase();

    // operator overload
    Number operator+(const Number& input_num);
    Number operator-(const Number& input_num);
    Number operator*(const Number& input_num);
    Number operator/(const Number& input_num);

    string to_string();
};
