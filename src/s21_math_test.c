#include "s21_math.h"

#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

START_TEST(abs_check) {
  ck_assert_int_eq(s21_abs(-8), abs(-8));
  ck_assert_int_eq(s21_abs(-1), abs(-1));
  ck_assert_int_eq(s21_abs(5), abs(5));
  ck_assert_int_eq(s21_abs(-2147483647), abs(-2147483647));
  ck_assert_int_eq(s21_abs(-0), abs(-0));
  ck_assert_int_eq(s21_abs(-03), abs(-03));
  ck_assert_int_eq(s21_abs(123456789), abs(123456789));
  ck_assert_int_eq(s21_abs(100), abs(100));
  ck_assert_int_eq(s21_abs(-100), abs(-100));
  ck_assert_int_eq(s21_abs(0), abs(0));
}
END_TEST

START_TEST(ceil_check) {
  ck_assert_ldouble_eq(s21_ceil(1.2), ceil(1.2));
  ck_assert_ldouble_eq(s21_ceil(10.978567), ceil(10.978567));
  ck_assert_ldouble_eq(s21_ceil(10009.00123), ceil(10009.00123));
  ck_assert_ldouble_eq(s21_ceil(-7.0), ceil(-7.0));
  ck_assert_ldouble_eq(s21_ceil(-12.23), ceil(-12.23));
  ck_assert_ldouble_eq(s21_ceil(12), ceil(12));
  ck_assert_ldouble_eq(s21_ceil(0), ceil(0));
  ck_assert_ldouble_eq(s21_ceil(-25.5556), ceil(-25.5556));
  ck_assert_ldouble_eq(s21_ceil(-10009.555), ceil(-10009.555));
  ck_assert_ldouble_eq(s21_ceil(-0.10009), ceil(-0.10009));
  ck_assert_ldouble_nan(s21_ceil(0.0 / 0.0));
  ck_assert_ldouble_eq(s21_ceil(S21_INF), ceil(INFINITY));
  ck_assert_ldouble_eq(s21_ceil(-S21_INF), ceil(-INFINITY));
}
END_TEST

START_TEST(floor_check) {
  ck_assert_ldouble_eq(s21_floor(1.2), floor(1.2));
  ck_assert_ldouble_eq(s21_floor(10.978567), floor(10.978567));
  ck_assert_ldouble_eq(s21_floor(-7.0), floor(-7.0));
  ck_assert_ldouble_eq(s21_floor(-12.23), floor(-12.23));
  ck_assert_ldouble_eq(s21_floor(12), floor(12));
  ck_assert_ldouble_eq(s21_floor(10009.00123), floor(10009.00123));
  ck_assert_ldouble_eq(s21_floor(0), floor(0));
  ck_assert_ldouble_eq(s21_floor(-1555.232222), floor(-1555.232222));
  ck_assert_ldouble_eq(s21_floor(-10009.555), floor(-10009.555));
  ck_assert_ldouble_eq(s21_floor(S21_INF), floor(INFINITY));
  ck_assert_ldouble_eq(s21_floor(-S21_INF), floor(-INFINITY));
  ck_assert_ldouble_nan(s21_floor(S21_NAN));
}
END_TEST

START_TEST(fmod_check) {
  ck_assert_double_eq_tol(s21_fmod(1, 2), fmod(1, 2), 1e-6);
  ck_assert_double_eq_tol(s21_fmod(145.4673, 12.3), fmod(145.4673, 12.3), 1e-6);
  ck_assert_double_eq_tol(s21_fmod(4, 2), fmod(4, 2), 1e-6);
  ck_assert_double_eq_tol(s21_fmod(-12.67, 3.4), fmod(-12.67, 3.4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(9.5, 3.5), fmod(9.5, 3.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(6.23213, 2.42), fmod(6.23213, 2.42), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(6, 2.5), fmod(6, 2.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(-6, 2), fmod(-6, 2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(6, -2), fmod(6, -2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(-6, -2), fmod(-6, -2), 1e-6);
  ck_assert_ldouble_nan(s21_fmod(0, 0));
  ck_assert_ldouble_nan(s21_fmod(1, 0));
  ck_assert_ldouble_nan(s21_fmod(S21_INF, -1));
  ck_assert_ldouble_eq(s21_fmod(-1, -S21_INF), fmod(-1, -INFINITY));
  ck_assert_ldouble_eq(s21_fmod(0, S21_INF), fmod(0, INFINITY));
  ck_assert_ldouble_nan(s21_fmod(0, S21_NAN));
  ck_assert_ldouble_nan(s21_fmod(S21_NAN, S21_NAN));
  ck_assert_ldouble_nan(s21_fmod(S21_NAN, S21_INF));
  ck_assert_ldouble_nan(s21_fmod(S21_INF, S21_NAN));
  ck_assert_ldouble_nan(s21_fmod(S21_NAN, -S21_INF));
  ck_assert_ldouble_nan(s21_fmod(-S21_INF, S21_NAN));
  ck_assert_ldouble_nan(s21_fmod(S21_INF, S21_INF));
}
END_TEST

START_TEST(exp_check) {
  ck_assert_ldouble_eq_tol(s21_exp(1), exp(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(10), exp(10), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(0), exp(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(12), exp(12), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(-1), exp(-1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(-15), exp(-15), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(3.3333), exp(3.3333), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(0.4564), exp(0.4564), 1e-6);
  ck_assert_ldouble_nan(s21_exp(S21_NAN));
  ck_assert_ldouble_eq(s21_exp(S21_INF), exp(INFINITY));
}
END_TEST

START_TEST(fabs_check) {
  ck_assert_ldouble_eq_tol(s21_fabs(-11245123.23), fabs(-11245123.23), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fabs(1023.l), fabs(1023.f), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fabs(0.l), fabs(0.f), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fabs(-12.456), fabs(-12.456), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fabs(-1.1), fabs(-1.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fabs(-0.10009), fabs(-0.10009), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fabs(-0.0), fabs(-0.0), 1e-6);
  ck_assert_ldouble_eq(s21_fabs(-S21_INF), fabs(-INFINITY));
  ck_assert_double_eq(s21_fabs(S21_INF), fabs(INFINITY));
  ck_assert_ldouble_nan(s21_fabs(S21_NAN));
}
END_TEST

START_TEST(log_check) {
  ck_assert_double_eq_tol(s21_log(1), log(1), 1e-6);
  ck_assert_double_eq_tol(s21_log(0.004), log(0.004), 1e-6);
  ck_assert_double_eq_tol(s21_log(10), log(10), 1e-6);
  ck_assert_double_eq_tol(s21_log(100), log(100), 1e-6);
  ck_assert_double_eq_tol(s21_log(0x14BD), log(0x14BD), 1e-6);
  ck_assert_ldouble_eq(s21_log(0.0), log(0.0));
  ck_assert_double_eq_tol(s21_log(12), log(12), 1e-6);
  ck_assert_ldouble_nan(s21_log(-1));
  ck_assert_int_eq(isnan(s21_log(S21_NAN)), 1);
  ck_assert_ldouble_eq(s21_log(S21_INF), log(INFINITY));
  ck_assert_ldouble_nan(s21_log(-S21_INF));
  ck_assert_ldouble_eq(s21_log(S21_M_E), log(S21_M_E));
  ck_assert_ldouble_nan(s21_log(-S21_M_E));
}
END_TEST

START_TEST(pow_check) {
  ck_assert_ldouble_eq_tol(s21_pow(0, 1), pow(0, 1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(1, 2), pow(1, 2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(0, 0), pow(0, 0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(12, 0), pow(12, 0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(-1, 2), pow(-1, 2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(-15, 3), pow(-15, 3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(-3, 4), pow(-3, 4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(-15, -3), pow(-15, -3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(15, -3), pow(15, -3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(15, -3.45), pow(15, -3.45), 1e-6);
  ck_assert_int_eq(isnan(s21_pow(-15, 3.45)), 1);
  ck_assert_int_eq(isnan(s21_pow(-15, -3.45)), 1);
  ck_assert_ldouble_eq_tol(s21_pow(23, 10), pow(23, 10), 1e+6);
  ck_assert_ldouble_nan(s21_pow(S21_NAN, S21_INF));
  ck_assert_ldouble_nan(s21_pow(S21_INF, S21_NAN));
  ck_assert_ldouble_nan(s21_pow(S21_NAN, -S21_INF));
  ck_assert_ldouble_nan(s21_pow(-S21_INF, S21_NAN));
  ck_assert_ldouble_nan(s21_pow(-0.789456, -0.789456));
  ck_assert_ldouble_nan(s21_pow(-500.789456, -10.1354323));
  ck_assert_ldouble_nan(s21_pow(-500.789456, 34.13));
  ck_assert_ldouble_eq(s21_pow(S21_INF, 0), pow(INFINITY, 0));
  ck_assert_ldouble_nan(s21_pow(0, S21_NAN));
  ck_assert_ldouble_nan(s21_pow(S21_NAN, S21_NAN));
  ck_assert_ldouble_eq(s21_pow(S21_INF, -S21_INF), pow(INFINITY, -INFINITY));
  ck_assert_ldouble_eq(s21_pow(S21_INF, -1), pow(INFINITY, -1));
  ck_assert_ldouble_eq(s21_pow(-S21_INF, -1), pow(-INFINITY, -1));
  ck_assert_ldouble_eq(s21_pow(0, S21_INF), pow(0, INFINITY));
  ck_assert_ldouble_eq(s21_pow(1, S21_INF), pow(1, INFINITY));
  ck_assert_ldouble_eq(s21_pow(-1, S21_INF), pow(-1, INFINITY));
  ck_assert_ldouble_eq(s21_pow(-1, -S21_INF), pow(-1, -INFINITY));
  ck_assert_ldouble_eq(s21_pow(S21_INF, 0), pow(INFINITY, 0));
  ck_assert_ldouble_eq(s21_pow(-S21_INF, 0), pow(-INFINITY, 0));
  ck_assert_ldouble_eq(s21_pow(S21_INF, S21_INF), pow(INFINITY, INFINITY));
  ck_assert_ldouble_eq(s21_pow(-S21_INF, S21_INF), pow(-INFINITY, INFINITY));
  ck_assert_ldouble_eq(s21_pow(S21_INF, 1), pow(INFINITY, 1));
  ck_assert_ldouble_eq(s21_pow(0, -S21_INF), pow(0, -INFINITY));
  ck_assert_ldouble_eq(s21_pow(0, -1), pow(0, -1));
  ck_assert_ldouble_eq(s21_pow(-S21_INF, 1), pow(-INFINITY, 1));
  ck_assert_ldouble_eq(s21_pow(2, S21_INF), pow(2, INFINITY));
  ck_assert_ldouble_eq(s21_pow(-2, S21_INF), pow(-2, INFINITY));
  ck_assert_ldouble_eq(s21_pow(2, -S21_INF), pow(2, -INFINITY));
  ck_assert_ldouble_eq(s21_pow(-2, -S21_INF), pow(-2, -INFINITY));
  ck_assert_ldouble_eq(s21_pow(0.5, S21_INF), pow(0.5, INFINITY));
  ck_assert_ldouble_eq(s21_pow(-0.5, S21_INF), pow(-0.5, INFINITY));
  ck_assert_ldouble_eq(s21_pow(0.5, -S21_INF), pow(0.5, -INFINITY));
  ck_assert_ldouble_eq(s21_pow(-0.5, -S21_INF), pow(-0.5, -INFINITY));
}
END_TEST

START_TEST(sqrt_check) {
  ck_assert_double_eq_tol(s21_sqrt(1), sqrt(1), 1e-6);
  ck_assert_double_eq_tol(s21_sqrt(10), sqrt(10), 1e-6);
  ck_assert_double_eq_tol(s21_sqrt(100), sqrt(100), 1e-6);
  ck_assert_double_eq_tol(s21_sqrt(178), sqrt(178), 1e-6);
  ck_assert_double_eq_tol(s21_sqrt(0), sqrt(0), 1e-6);
  ck_assert_double_eq_tol(s21_sqrt(12), sqrt(12), 1e-6);
  ck_assert_int_eq(isnan(s21_sqrt(-1)), 1);
  ck_assert_ldouble_nan(s21_sqrt(S21_NAN));
  ck_assert_ldouble_eq(s21_sqrt(S21_INF), sqrt(INFINITY));
  ck_assert_ldouble_nan(s21_sqrt(-S21_INF));
}
END_TEST

START_TEST(sin_check) {
  ck_assert_double_eq_tol(s21_sin(-0.99), sin(-0.99), 1e-8);
  ck_assert_double_eq_tol(s21_sin(1), sin(1), 1e-6);
  ck_assert_double_eq_tol(s21_sin(10), sin(10), 1e-6);
  ck_assert_double_eq_tol(s21_sin(9809.9), sin(9809.9), 1e-8);
  ck_assert_double_eq_tol(s21_sin(0x14BD), sin(0x14BD), 1e-6);
  ck_assert_double_eq_tol(s21_sin(145), sin(145), 1e-6);
  ck_assert_double_eq_tol(s21_sin(16), sin(16), 1e-6);
  ck_assert_double_eq_tol(s21_sin(5), sin(5), 1e-6);
  ck_assert_double_eq_tol(s21_sin(7), sin(7), 1e-6);
  ck_assert_double_eq_tol(s21_sin(-16), sin(-16), 1e-6);
  ck_assert_double_eq_tol(s21_sin(145986), sin(145986), 1e-6);
  ck_assert_int_eq(isnan(s21_sin(S21_NAN)), 1);
  ck_assert_ldouble_nan(s21_sin(S21_INF));
  ck_assert_ldouble_nan(s21_sin(-S21_INF));
}

START_TEST(cos_check) {
  ck_assert_double_eq_tol(s21_cos(-1), cos(-1), 1e-6);
  ck_assert_double_eq_tol(s21_cos(1), cos(1), 1e-6);
  ck_assert_double_eq_tol(s21_cos(10), cos(10), 1e-6);
  ck_assert_double_eq_tol(s21_cos(0), cos(0), 1e-6);
  ck_assert_double_eq_tol(s21_cos(0x14BD), cos(0x14BD), 1e-6);
  ck_assert_double_eq_tol(s21_cos(145), cos(145), 1e-6);
  ck_assert_double_eq_tol(s21_cos(16), cos(16), 1e-6);
  ck_assert_double_eq_tol(s21_cos(5), cos(5), 1e-6);
  ck_assert_double_eq_tol(s21_cos(7), cos(7), 1e-6);
  ck_assert_double_eq_tol(s21_cos(-16), cos(-16), 1e-6);
  ck_assert_double_eq_tol(s21_cos(145986), cos(145986), 1e-6);
  ck_assert_int_eq(isnan(s21_cos(S21_NAN)), 1);
  ck_assert_ldouble_nan(s21_cos(S21_INF));
  ck_assert_ldouble_nan(s21_cos(-S21_INF));
}
END_TEST

START_TEST(tan_check) {
  ck_assert_double_eq_tol(s21_tan(-1), tan(-1), 1e-6);
  ck_assert_double_eq_tol(s21_tan(1), tan(1), 1e-6);
  ck_assert_double_eq_tol(s21_tan(10), tan(10), 1e-6);
  ck_assert_double_eq_tol(s21_tan(0), tan(0), 1e-6);
  ck_assert_double_eq_tol(s21_tan(0x14BD), tan(0x14BD), 1e-6);
  ck_assert_double_eq_tol(s21_tan(145), tan(145), 1e-6);
  ck_assert_double_eq_tol(s21_tan(16), tan(16), 1e-6);
  ck_assert_double_eq_tol(s21_tan(-16), tan(-16), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(-0.0), tan(-0.0), 1e-6);
  ck_assert_int_eq(isnan(s21_tan(S21_NAN)), 1);
  ck_assert_ldouble_nan(s21_tan(S21_INF));
  ck_assert_ldouble_nan(s21_tan(-S21_INF));
  ck_assert_ldouble_eq_tol(s21_tan(S21_PI_2), tan(S21_PI_2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(-S21_PI_2), tan(-S21_PI_2), 1e-6);
}
END_TEST

START_TEST(asin_check) {
  ck_assert_double_eq_tol(s21_asin(-1), asin(-1), 1e-6);
  ck_assert_double_eq_tol(s21_asin(1), asin(1), 1e-6);
  ck_assert_double_eq_tol(s21_asin(0.8), asin(0.8), 1e-6);
  ck_assert_double_eq_tol(s21_asin(0.2), asin(0.2), 1e-6);
  ck_assert_int_eq(isnan(s21_asin(2)), 1);
  ck_assert_double_eq_tol(s21_asin(0), asin(0), 1e-6);
  ck_assert_int_eq(isnan(s21_asin(-2)), 1);
  ck_assert_ldouble_nan(s21_asin(-255.98));
  ck_assert_ldouble_nan(s21_asin(S21_NAN));
  ck_assert_ldouble_nan(s21_asin(S21_INF));
  ck_assert_ldouble_nan(s21_asin(-S21_INF));
}
END_TEST

START_TEST(acos_check) {
  ck_assert_double_eq_tol(s21_acos(-1), acos(-1), 1e-6);
  ck_assert_double_eq_tol(s21_acos(1), acos(1), 1e-6);
  ck_assert_double_eq_tol(s21_acos(0.2), acos(0.2), 1e-6);
  ck_assert_double_eq_tol(s21_acos(0.8), acos(0.8), 1e-6);
  ck_assert_double_eq_tol(s21_acos(-0.7), acos(-0.7), 1e-6);
  ck_assert_int_eq(isnan(s21_acos(2)), 1);
  ck_assert_double_eq_tol(s21_acos(0), acos(0), 1e-6);
  ck_assert_int_eq(isnan(s21_acos(S21_NAN)), 1);
  ck_assert_ldouble_nan(s21_acos(S21_INF));
  ck_assert_ldouble_nan(s21_acos(-S21_INF));
}
END_TEST

START_TEST(atan_check) {
  ck_assert_double_eq_tol(s21_atan(-1), atan(-1), 1e-6);
  ck_assert_double_eq_tol(s21_atan(1), atan(1), 1e-6);
  ck_assert_double_eq_tol(s21_atan(145), atan(145), 1e-6);
  ck_assert_double_eq_tol(s21_atan(10), atan(10), 1e-6);
  ck_assert_double_eq_tol(s21_atan(0x14BD), atan(0x14BD), 1e-6);
  ck_assert_double_eq_tol(s21_atan(0), atan(0), 1e-6);
  ck_assert_double_eq_tol(s21_atan(16), atan(16), 1e-6);
  ck_assert_double_eq_tol(s21_atan(0.5), atan(0.5), 1e-6);
  ck_assert_double_eq_tol(s21_atan(2), atan(2), 1e-6);
  ck_assert_double_eq_tol(s21_atan(145986), atan(145986), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-S21_INF), atan(-INFINITY), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(S21_INF), atan(INFINITY), 1e-6);
}
END_TEST

int main(void) {
  Suite *s = suite_create("Core");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, abs_check);
  tcase_add_test(tc, ceil_check);
  tcase_add_test(tc, floor_check);
  tcase_add_test(tc, exp_check);
  tcase_add_test(tc, fabs_check);
  tcase_add_test(tc, fmod_check);
  tcase_add_test(tc, log_check);
  tcase_add_test(tc, pow_check);
  tcase_add_test(tc, sqrt_check);
  tcase_add_test(tc, sin_check);
  tcase_add_test(tc, cos_check);
  tcase_add_test(tc, tan_check);
  tcase_add_test(tc, asin_check);
  tcase_add_test(tc, acos_check);
  tcase_add_test(tc, atan_check);

  suite_add_tcase(s, tc);

  SRunner *sr = srunner_create(s);
  int fc;

  srunner_run_all(sr, CK_ENV);
  fc = srunner_ntests_failed(sr);
  srunner_free(sr);
  return fc == 0 ? 0 : 1;
}
