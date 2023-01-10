#include <errno.h>
#include <float.h>
#include <math.h>
#include <stdio.h>  // NOLINT
#include "s21_decemal.h"
void s21_print_decimal(s21_decimal dec) {
  printf("exp - %d ", dec.bits_.exp);
  printf("sign - %d ", dec.bits_.sign);
  printf("byte2 - %d ", dec.bits_.byte2);
  printf("byte1 - %d ", dec.bits_.byte1);
  printf("byte0 - %d ", dec.bits_.byte0);
  printf("\n");
}



int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  s21_decimal t;
  t.bits_.exp = 3;
  t.bits_.sign = 0;
  t.bits_.byte2 = 0;
  t.bits_.byte1= 0;
  t.bits_.byte0 = 0;

  t.value_type = NORM;
  dst = &t;
  return 0;
}

int main() {
  s21_decimal t;
  if (s21_from_int_to_decimal(10, &t) == 0) {
    s21_print_decimal(t);
  }
  
  return 0;
}
