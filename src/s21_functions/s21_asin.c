#include "../s21_math.h"

long double s21_asin(double x) {
  long double asin = 0.0;
  if (x > 0 && x < 0.5) {
    for (int i = 0; i < 30; i++) {
      long double res = 0.0;
      long int i_2 = 2 * i;
      long int f_ch = s21_factorial(i_2);
      long int f_zn = s21_factorial(i);
      res = (s21_pow(x, 2 * i + 1)) * f_ch /
            (f_zn * f_zn * (s21_pow(4, i)) * (2 * i + 1));
      asin = asin + res;
    }
  } else if (x >= 0.5 && x <= 1) {
    asin = S21_PI_2 - 2 * s21_asin(s21_sqrt((1 - x) / 2));
  } else if (x >= -1 && x < 0) {
    x = -x;
    asin = -s21_asin(x);
  }
  return (x >= -1 && x <= 1) ? asin : S21_NAN;
}