#include <math.h>

#include "../s21_math.h"
long double s21_acos(double x) {
  double acos = 0.0;
  if ((x > 0) && (x <= 1)) {
    acos = s21_asin(s21_sqrt(1 - s21_pow(x, 2)));
  } else if ((x >= -1) && (x < 0)) {
    acos = S21_PI - s21_asin(s21_sqrt(1 - s21_pow(x, 2)));
  } else if (x == 0) {
    acos = S21_PI_2;
  }
  return (x >= -1 && x <= 1) ? acos : S21_NAN;
}
