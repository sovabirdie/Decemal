#include <stdio.h>

#include "s21_math.h"
#include "s21_math_extra.h"

long double s21_sin(double x) {
  long double eps = (x < 0) ? -S21_EPS / 10 : S21_EPS / 10;
  return (s21_cos_sin(
             x, 1,
             (S21_ISNAN(x) || s21_fabs(x) == S21_INF) ? x : def_quarter(x))) +
         eps;
}

long double s21_cos(double x) { return s21_cos_sin(x, 0, 1L); }

long double s21_atan(double x) {
  long double res = 0;
  long double denominator = 1;
  long double numerator = x;
  int sign = 1;

  if (s21_fabs(x) == S21_INF) {
    res = x > 0 ? 0.5 * S21_PI : -0.5 * S21_PI;
  } else if (s21_fabs(x) == 1.) {
    res = 0.25 * x * S21_PI;
  } else if (s21_fabs(x) < 1.) {
    while (s21_fabs(sign * numerator / denominator) >= S21_EPS) {
      res = res + sign * numerator / denominator;
      sign = -sign;
      numerator *= (x * x);
      denominator += 2;
    }
  } else if (s21_fabs(x) > 1.) {
    while (s21_fabs(sign / (numerator * denominator)) >= S21_EPS) {
      res = res + sign / (numerator * denominator);
      sign = -sign;
      numerator *= (x * x);
      denominator += 2;
    }
    res = S21_PI * s21_fabs(x) / (2 * x) - res;
  } else if (S21_ISNAN(x)) {
    res = S21_NAN;
  }
  return res;
}

long double s21_asin(double x) {
  long double res = 0;
  if (s21_fabs(x) == 1.) {
    res = x * 0.5 * S21_PI;
  } else if (s21_fabs(x) < 1) {
    res = s21_atan(x / s21_sqrt(1 - x * x));
  } else {
    res = (x < 0) ? -S21_NAN : S21_NAN;
  }
  return res;
}

long double s21_acos(double x) {
  long double res = 0;
  if (s21_fabs(x) == 0.) {
    res = 0.5 * S21_PI;
  } else if (x == 1.) {
    res = 0;
  } else if (x == -1.) {
    res = S21_PI;
  } else if (x > 0. && x < 1.) {
    res = s21_atan(s21_sqrt(1 - x * x) / x);
  } else if (x > -1. && x < 0.) {
    res = S21_PI + s21_atan(s21_sqrt(1 - x * x) / x);
  } else {
    res = S21_NAN;
  }
  return res;
}

long double s21_tan(double x) {
  x = def_quarter(x);
  return s21_sin(x) / s21_cos(x);
}
