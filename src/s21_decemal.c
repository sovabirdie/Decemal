#include "s21_decemal.h"


void s21_print_decimal(s21_decimal dec) {
  for (int i = 0; i < 4; i ++) {
    int t = dec.bits[i];
    for (int k = 0; i < 32; i ++) {
      printf('%c',  t % 2);
      t /= 2;
    }
    printf(' ');
  }
  printf('\n');
}
