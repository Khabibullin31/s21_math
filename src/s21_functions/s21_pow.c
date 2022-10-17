#include "../s21_math.h"

long double s21_pow(double base, double exp) {
  long double pow = 1;

  if (base == -S21_INF && exp == S21_INF) {
    pow = S21_INF;
  } else if ((base < 0) && (base > -1) && (exp == S21_INF)) {
    pow = 0;
  } else if ((base < 0) && (base > -1) && (exp == -S21_INF)) {
    pow = S21_INF;
  } else if ((base == 1 || base == -1) && (exp == S21_INF || exp == -S21_INF)) {
    pow = 1;
  } else if ((base < 0) && (base - (int)base != 0) && (exp - (int)exp != 0)) {
    pow = S21_NAN;
  } else if ((base < 0) && ((int)exp % 2 != 0) && (exp - (int)exp == 0)) {
    base = -base;
    pow = s21_exp(exp * s21_log(base));
    pow = -pow;
  } else if (exp == 0) {
    pow = 1;
  } else if ((base < 0) && ((int)exp % 2 == 0)) {
    base = -base;
    pow = s21_exp(exp * s21_log(base));
  } else
    pow = s21_exp(exp * s21_log(base));

  return pow;
}
