#include "s21_math.h"
#include "s21_math_extra.h"

long double s21_exp(double x) {
  long double res = 1;
  long double res1 = 1;
  
  if (x != 0) { 
    while (s21_fabs(x) >= 1) { //отбросить целое число
      if (x > 0) {x -= 1; res1 *= S21_M_E;}
      if (x < 0) {x += 1; res1 *= 1 / S21_M_E;}
    }
    //if ((int)x != x){
    if (s21_ceil(x) != s21_floor(x)){  
      long double numerator = x;
      long double denominator = 1;
      int i = 2;
      //while ((s21_fabs(numerator / denominator)>= S21_EPS / 100) || denominator!=0 )  {
      for (int i = 2; i < 200; i++) {
        res += numerator / denominator;
        numerator *= x;
        denominator *= i;
        // i++;
      }
    }
  }
  return res * res1;
}

long double s21_log(double x) {
  long double res = 0;
  if (x < 0) {
    res = -S21_NAN;
  }
  if (x == 0) {
    res = -S21_INF;
  }
  if (x == 1) {
    res = 0;
  }
  if (x > 0 && x != 1) {
    while (x > 1) {
      x /= S21_M_E;
      res++;
    }
    res += s21_ln(x);
  }
  return res;
}
