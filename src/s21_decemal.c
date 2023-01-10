#include "s21_decemal.h"


void s21_print_decimal(s21_decimal dec) {
  printf("%d ", dec.bits_.exp);
  printf("%d ", dec.bits_.sign);
  printf("%d ", dec.bits_.byte2);
  printf("%d ", dec.bits_.byte1);
  printf("%d ", dec.bits_.byte0);
  printf(' ');
  printf('\n');
}
