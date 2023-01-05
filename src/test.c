#include <errno.h>
#include <float.h>
#include <math.h>
#include <stdio.h>  // NOLINT

#include "s21_decemal.h"

int main() {
  // double x;
  double n = -1;
  // DBL_MAX÷
  // printf("sin: %.20Lf %.20Lf\n", sinl(n), s21_sin(n));
  // printf("cos: %.20Lf %.20Lf\n", cosl(n), s21_cos(n));
  printf("tan: %.20Lf %.20Lf\n", acosl(n), s21_acos(n));
  // for (x = -40; x < 40; x += 0.001) {
  //   if (fabs(s21_sin(x)- sin(x)) > S21_EPS) {
  //   printf("x=%.20lf  my%.20Lf|  rl%.20lf|\n", x, s21_sin(x), sin(x));
  //   }
  // }
  return 0;
}
