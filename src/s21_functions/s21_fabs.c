#include "../s21_math.h"

long double s21_fabs(double x) {
  if (x == S21_INF) {
    x = S21_INF;
  } else if (x == -S21_INF) {
    x = S21_INF;
  } else if (x != x) {
    x = S21_NAN;

  } else if (x < 0)
    x = x * (-1);
  return x;
}