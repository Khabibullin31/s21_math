#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_
#include <stdio.h>

#define S21_NAN 0.0 / 0.0
#define S21_INF 1.0 / 0.0
#define S21_LN_10 2.30258509299
#define S21_LN_2 0.69314718056
#define S21_2PI 6.283185307179586476925286766559005768394338798750211641949888
#define S21_PI 3.141592653589793238462643383279502884197169399375105820974944
#define S21_PI_2 1.570796326794896619231321691639751442098584699687552910487472
#define S21_ATAN_0_5 0.463647609
#define S21_ATAN_1 0.78539816339
#define S21_ATAN_1_5 0.98279372324
#define S21_M_E 2.718281828459045236
#define S21_TAN_PI2 16331239353195370.000000

int s21_abs(int x);
long double s21_acos(double x);
long double s21_fabs(double x);
long double s21_ceil(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_pow(double base, double exp);
long double s21_sqrt(double x);
long double s21_exp(double x);
long double s21_log(double x);
long double s21_sin(double x);
long double s21_cos(double x);
long double s21_tan(double x);
long double s21_asin(double x);
long double s21_acos(double x);
long double s21_atan(double x);
int s21_factorial(int x);

#endif  // SRC_S21_MATH_H_