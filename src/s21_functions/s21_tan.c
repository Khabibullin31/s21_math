#include "../s21_math.h"

long double s21_tan(double x) {
  long double tan = 0.0;
  if (x == S21_PI_2) {
    tan = S21_TAN_PI2;
  } else if (x == -S21_PI_2) {
    tan = -S21_TAN_PI2;
  } else {
    tan = s21_sin(x) / s21_cos(x);
  }
  return tan;
}
