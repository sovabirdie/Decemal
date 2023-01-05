#ifndef SRC_S21_DECEMAL_VAR_H_
#define SRC_S21_DECEMAL_VAR_H_

#define S21_M_E 2.7182818284590452354 /* e */

#define S21_NAN \
  -(0.0 / 0.0)  // <---------------------------------------------------
#define S21_INF \
  1.0 / 0.0  // <--------------------------------------------------------

typedef enum {
  ZER,    // [0, PI/2)
  PI_2,   // [PI/2, PI)
  PI,     // [PI, PI*3/2)
  PI3_2,  // [PI*3/2, 2PI)
  ERROR,
} quart;

enum {LOW, MID, HIGH, SCALE};

typedef enum {
  NORM,
  INF,
  N_INF,
  NAAN,
  DOP_CODE
} value_type_t;

typedef struct {
    int bits[4];

  //unsigned int bits[4];
  value_type_t value_type;  
} s21_decimal;



union converter {
  int number;
  char bytes[4];
} ;  

/*
typedef struct 
{
  union num {
    int number;
    char bytes[4];
  } ; 
} s21_decimal;



union converter {
  int number;
  char bytes[4];
} ;  
*/

/*

#include <stdio.h>
union converter {
 int number;
 char bytes[4];
}; 
int main(void)
{
    union converter id;
    id.number = 0x2211;//8721 0000 0000 0000 0000 0010 0010 0001 0001
    printf("%d - %d \n", id.number, id.bytes[0]);  //0001 0001
    printf("%d - %d \n", id.number, id.bytes[1]);  //0010 0010
    printf("%d - %c \n", id.number, id.bytes[2]);  //0000 0000
    printf("%d - %c \n", id.number, id.bytes[3]);  //0000 0000
    return 0;
}

*/



#endif