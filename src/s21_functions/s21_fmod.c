#include "../s21_math.h"

long double s21_fmod(double x, double y) {
  long double z = 0.0, w = 0.0;

  if (y == 0) {
    w = S21_NAN;
  } else if (x == S21_INF) {
    w = S21_NAN;
  } else if (x == -1 && (y == S21_INF || y == -S21_INF)) {
    w = -1;
  } else if (x == 0 && (y == S21_INF || y == -S21_INF)) {
    w = 0;
  } else {
    z = (int)(x / y);
    w = (x - z * y);
  }

  return w;
}
