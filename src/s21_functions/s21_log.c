#include "../s21_math.h"
long double res_l(double k, int y, long double log_r);
long double s21_log(double x) {
  long double log = 0.0;
  double f = 0.0;
  int n = 0, k = 0;

  if (x < 0) {
    log = S21_NAN;
  } else if (x == 0) {
    log = -S21_INF;
  } else if (x == S21_INF) {
    log = S21_INF;
  } else if (x == S21_M_E) {
    log = 1;
  } else {
    while (x >= 10.0) {
      x = (double)(x / 10.0);
      n++;
    }
    while (x >= 2.0) {
      x = (double)(x / 2.0);
      k++;
    }
    f = x - 1.0;

    if (x < 0.005) {
      for (int j = 1; j < 35000; j++) {
        log = res_l(f, j, log);
      }
    } else {
      for (int j = 1; j < 2000; j++) {
        log = res_l(f, j, log);
      }
    }
    log = log + (double)n * S21_LN_10 + (double)k * S21_LN_2;
  }
  return log;
}

long double res_l(double k, int y, long double log_r) {
  long double res_r = 1.0;
  for (int i = 1; i <= y; i++) {
    res_r = res_r * k;
  }
  if (y % 2 == 0) {
    log_r = log_r - res_r / (double)y;
  } else {
    log_r = log_r + res_r / (double)y;
  }
  return log_r;
}
