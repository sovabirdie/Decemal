#include "s21_math.h"

long double s21_pow(double x, double y) {
  long double res = 1;
  if (x != 0.0 && y == 0.0) {
    res = 1;
  }
  if (x == 0.0 && y == 0.0) {
    res = 1;
  } else if (x == 0 && y < 0) {
    res = S21_INF;
  } else if (x == 0 && y > 0) {
    res = 0;
  } else if (x < 0 && ((int)y != y)) {
    res = S21_NAN;
  } else if (x < 0 && ((int)y == y)) {
    for (int i = 0; i < s21_abs(y); i++) {
      res *= x;
    }
    if (y < 0) {
      res = 1 / res;
    }
  } else if (y < 0) {
    res = 1.0 / s21_exp(-y * s21_log(x));
  } else if (y > 0) {
    res = s21_exp(y * s21_log(x));
  }
  return res;
}
long double s21_sqrt(double x) {
  long double res = 0;
  if (x < 0) {
    res = -S21_NAN;
  }
  if (x > 0) {
    res = s21_pow(x, 0.5);
  }
  return res;
}
