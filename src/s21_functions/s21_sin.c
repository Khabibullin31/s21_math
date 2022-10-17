#include "../s21_math.h"

long double s21_sin(double x) {
  long double sin = 0.0;
  int sc = 0;

  if (x == S21_INF) {
    sin = S21_INF;
  } else if (x == -S21_INF) {
    sin = -S21_INF;
  } else if (x != x) {
    sin = S21_NAN;

  } else if (x >= 0) {
    while ((s21_fabs(x) / S21_2PI) >= 1) {
      x = x - S21_2PI;
    }
  } else if (x < 0) {
    while ((x / S21_2PI) <= 1) {
      x = x + S21_2PI;
    }
  }
  for (int j = 1; j < 50; j = j + 2) {
    long double res_r = 1.0;
    sc++;
    for (int i = 1; i <= j; i++) {
      res_r = res_r * x / i;
    }
    if (sc % 2 == 0) {
      sin = sin - res_r;
    } else {
      sin = sin + res_r;
    }
  }
  return sin;
}
