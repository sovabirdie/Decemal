#include "s21_math.h"

int s21_abs(int x) {
  if (x < 0) x = -x;
  return x;
}

long double s21_fabs(double x) {
  if (x < 0) x = -x;
  return (long double)x;
}

long double s21_ceil(double x) {
  long double res = 0;
  if (s21_fabs(x) == S21_INF) {
    res = x;
  } else if (S21_ISNAN(x)) {
    res = S21_NAN;
  } else if (s21_fabs(x) > 0.) {
    res = (long long int)x;
    res = (res != x && x > 0.) ? res + 1 : res;
  }
  return res;
}

long double s21_floor(double x) {
  long double res = (long long int)x;
  if (s21_fabs(x) == S21_INF) {
    res = x;
  } else if (S21_ISNAN(x)) {
    res = S21_NAN;
  } else if (s21_fabs(x - res) > 0. && s21_fabs(x) > 0.)
    res = x < 0. ? res - 1 : res;
  return res;
}

long double s21_fmod(double x, double y) {
  long double res;
  if (s21_fabs(x) == S21_INF || s21_fabs(y) == 0) {
    res = -S21_NAN;
  } else if (s21_fabs(y) == S21_INF) {
    res = x;
  } else {
    long double dx = s21_fabs(x);
    long double dy = s21_fabs(y);
    while (dx >= 0) dx = dx - dy;
    dx = dx > (0. - S21_EPS) && dx < (0. + S21_EPS) ? +0. : dx;
    res = dx < 0. ? dx + dy : dx;
  }
  return res;
}