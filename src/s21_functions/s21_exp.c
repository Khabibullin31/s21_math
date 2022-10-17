#include "../s21_math.h"

long double s21_exp(double x) {
  long double exp = 0.0;
  if (x >= 0) {
    for (int k = 0; k < 400; k++) {
      long double res = 1.0;
      for (int i = 1; i <= k; i++) {
        res = res * x / i;
      }
      exp += res;
    }
  } else {
    for (int k = 0; k < 400; k++) {
      long double res = 1.0;
      for (int i = 1; i <= k; i++) {
        res = res * (-x) / i;
      }
      exp += res;
    }
    exp = 1 / exp;
  }

  return exp;
}