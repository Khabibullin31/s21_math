#include "../s21_math.h"

long double s21_floor(double x) {
  long int res = x;

  if (x == S21_INF) {
    x = S21_INF;
  } else if (x == -S21_INF) {
    x = -S21_INF;
  } else if (x != x) {
    x = S21_NAN;

  } else if (x - (int)x == 0) {
    x = x;
  } else if (x >= 0)
    x = (long double)res;
  else
    x = (long double)res - 1.0;
  return x;
}