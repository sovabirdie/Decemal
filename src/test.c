#include <errno.h>
#include <float.h>
#include <math.h>
#include <stdio.h>  // NOLINT
#include "s21_decemal.h"
void s21_print_decimal(s21_decimal dec) {
  for (int i = 0; i < 4; i ++) {
    int t = dec.bits[i];
    printf("%d",  t);
    //for (int k = 0; i < 32; i ++) {
    //  printf("%d",  t % 2);
    //  t /= 2;
    //}
    printf("  ");
  }
  printf("\n");
}


int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  s21_decimal t;
  union converter id;
  id.number = src;

  t.bits[3] = 0;
  t.bits[2] = (int)id.bytes[2];
  t.bits[1] = (int)id.bytes[1];
  t.bits[0] = (int)id.bytes[0];


  t.value_type = NORM;
  dst = &t;
  return 0;
}

int main() {
  s21_decimal t;
  if (s21_from_int_to_decimal(8721, &t) == 0) {
    s21_print_decimal(t);
  }
  
  return 0;
}
