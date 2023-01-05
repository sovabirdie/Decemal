#include "s21_math.h"

double def_quarter(double x) {
  double dec = S21_PI * 2.;
  if (x < 0) dec = -dec;
  while (!(x >= -S21_PI && x < S21_PI)) x -= dec;
  return x;
}

long double s21_ln(double x) {
  long double res = 0, b = x - 1, tmp = b;
  int n = 1;
  while (s21_fabs(tmp) >= S21_EPS / 10) {
    res += tmp;
    n++;
    b = (-1) * b * (x - 1);
    tmp = b / n;
  }
  return res;
}

long double s21_cos_sin(double x, int i, long double numerator) {
  long double res = 0;
  if (S21_ISNAN(x) || s21_fabs(x) == S21_INF) {
    res = S21_NAN;
  } else {
    x = def_quarter(x);
    long double denominator = 1;

    int sign = 1;
    long double member = sign * numerator / denominator;

    while (s21_fabs(member) > (S21_EPS)) {
      res = res + member;
      i = i + 2;
      sign = -sign;
      denominator *= ((i - 1) * i);
      numerator *= (x * x);
      member = sign * numerator / denominator;
    }
  }
  return res;
}
