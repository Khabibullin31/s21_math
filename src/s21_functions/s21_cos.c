#include "../s21_math.h"

long double s21_cos(double x) {
  long double cos = 0.0;
  int sc = 0;

  if (x == S21_INF) {
    cos = S21_INF;
  } else if (x == -S21_INF) {
    cos = -S21_INF;
  } else if (x != x) {
    cos = S21_NAN;

  } else if (x >= 0) {
    while ((s21_fabs(x) / S21_2PI) >= 1) {
      x = x - S21_2PI;
    }
  } else if (x < 0) {
    while ((x / S21_2PI) <= 1) {
      x = x + S21_2PI;
    }
  }
  for (int j = 0; j < 50; j = j + 2) {
    long double res_r = 1.0;
    sc++;
    for (int i = 1; i <= j; i++) {
      res_r = res_r * x / i;
    }
    if (sc % 2 == 0) {
      cos = cos - res_r;
    } else {
      cos = cos + res_r;
    }
  }
  return cos;
}