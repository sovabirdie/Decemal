#include "s21_decemal.h"


int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  s21_decimal t;
  union converter id;
  id.number = src;

  t.bits_.exp = 0;
  t.bits_.sign = 0;
  t.bits_.byte2 = id.bytes[2];
  t.bits_.byte1= id.bytes[1];
  t.bits_.byte0 = id.bytes[0];

  t.value_type = NORM;
  dst = &t;
  return 0;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  return 0;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  return 0;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  return 0;
}
