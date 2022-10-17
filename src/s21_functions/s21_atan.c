#include "../s21_math.h"

long double s21_atan(double x) {
  long double atan = 0.0;
  int sc = 0;

  if (x >= 0 && x < 7.0 / 16.0) {
    for (int j = 1; j < 1000; j = j + 2) {
      long double res_r = 1.0;
      sc++;
      for (int i = 1; i <= j; i++) {
        res_r = res_r * x;
      }
      if (sc % 2 == 0) {
        atan = atan - res_r / j;
      } else {
        atan = atan + res_r / j;
      }
    }
  } else if (x >= 7.0 / 16.0 && x < 11.0 / 16.0) {
    atan = S21_ATAN_0_5 + s21_atan((x - 0.5) / (1 + x / 2.0));
  } else if (x >= 11.0 / 16.0 && x < 19.0 / 16.0) {
    atan = S21_ATAN_1 + s21_atan((x - 1.0) / (1.0 + x));
  } else if (x >= 19.0 / 16.0 && x < 39.0 / 16.0) {
    atan = S21_ATAN_1_5 + s21_atan((x - 1.5) / (1.0 + 1.5 * x));
  } else if (x >= 39.0 / 16.0) {
    atan = S21_PI_2 + s21_atan(-1.0 / x);
  } else if (x < 0) {
    x = -x;
    atan = -s21_atan(x);
  }
  return atan;
}
