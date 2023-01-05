#ifndef SRC_S21_DECEMAL_VAR_H_
#define SRC_S21_DECEMAL_VAR_H_

#define S21_M_E 2.7182818284590452354 /* e */

#define S21_PI 3.14159265358979323846   /* pi */
#define S21_PI_2 1.57079632679489661923 /* pi/2 */

#define S21_EPS 1e-16  // точность до .. знака после запятой
#define S21_EPS_TEST 1e-06  // точность до .. знака после запятой
#define S21_ISNAN(X) ((X) != (X))
#define S21_NAN \
  -(0.0 / 0.0)  // <---------------------------------------------------
#define S21_INF \
  1.0 / 0.0  // <--------------------------------------------------------
#define S21_INT_MIN -2147483646
#define S21_INT_MAX 2147483647
typedef enum {
  ZER,    // [0, PI/2)
  PI_2,   // [PI/2, PI)
  PI,     // [PI, PI*3/2)
  PI3_2,  // [PI*3/2, 2PI)
  ERROR,
} quart;

typedef struct 
{
    int bits[4];
} s21_decimal;


#endif