#include "../s21_math.h"

int s21_factorial(int x) {
  int factorial = 1;
  for (int i = 1; i <= x; i++) {
    factorial = factorial * i;
  }
  return factorial;
}