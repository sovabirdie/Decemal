
#ifndef SRC_S21_DECEMAL_H_
#define SRC_S21_DECEMAL_H_

#include "s21_decemal_var.h"

/*
    Сложение	value_1 + value_2 => *result
    Функции возвращают код ошибки:
        0 - OK
        1 - число слишком велико или равно бесконечности
        2 - число слишком мало или равно отрицательной бесконечности
        3 - деление на 0
*/
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

/*
    Вычитание	value_1 - value_2 => *result
    Функции возвращают код ошибки:
        0 - OK
        1 - число слишком велико или равно бесконечности
        2 - число слишком мало или равно отрицательной бесконечности
        3 - деление на 0	
*/
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

/*
    Умножение	value_1 * value_2 => *result	
    Функции возвращают код ошибки:
        0 - OK
        1 - число слишком велико или равно бесконечности
        2 - число слишком мало или равно отрицательной бесконечности
        3 - деление на 0
*/
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);


/*
    Деление	value_1 / value_2 => *result	
    Функции возвращают код ошибки:
        0 - OK
        1 - число слишком велико или равно бесконечности
        2 - число слишком мало или равно отрицательной бесконечности
        3 - деление на 0
*/
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

/*
   Остаток от деления	value_1 на value_2 => *result	
   Функции возвращают код ошибки:
        0 - OK
        1 - число слишком велико или равно бесконечности
        2 - число слишком мало или равно отрицательной бесконечности
        3 - деление на 0
*/
int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

/*
    Меньше	<	
    Возвращаемое значение:
    0 - FALSE
    1 - TRUE
*/
int s21_is_less(s21_decimal, s21_decimal);
/*
    Меньше или равно	<=	
    Возвращаемое значение:
    0 - FALSE
    1 - TRUE
*/
int s21_is_less_or_equal(s21_decimal, s21_decimal);
/*
    Больше	>	
    Возвращаемое значение:
    0 - FALSE
    1 - TRUE
*/
int s21_is_greater(s21_decimal, s21_decimal);
/*
    Больше или равно	>=	
    Возвращаемое значение:
    0 - FALSE
    1 - TRUE
*/
int s21_is_greater_or_equal(s21_decimal, s21_decimal);
/*
    Равно	==	
    Возвращаемое значение:
    0 - FALSE
    1 - TRUE
*/
int s21_is_equal(s21_decimal, s21_decimal);
/*
    Не равно	!=	
    Возвращаемое значение:
    0 - FALSE
    1 - TRUE
*/
int s21_is_not_equal(s21_decimal, s21_decimal);

/*
    Из int
    Возвращаемое значение - код ошибки:
    0 - OK
    1 - ошибка конвертации
*/
int s21_from_int_to_decimal(int src, s21_decimal *dst);
/*
    Из float	
    Возвращаемое значение - код ошибки:
    0 - OK
    1 - ошибка конвертации
*/
int s21_from_float_to_decimal(float src, s21_decimal *dst);
/*
    В int	
    Возвращаемое значение - код ошибки:
    0 - OK
    1 - ошибка конвертации
*/
int s21_from_decimal_to_int(s21_decimal src, int *dst);
/*
    В float	
    Возвращаемое значение - код ошибки:
    0 - OK
    1 - ошибка конвертации
*/
int s21_from_decimal_to_float(s21_decimal src, float *dst);

/*
    Округляет указанное Decimal число до ближайшего целого числа в сторону отрицательной бесконечности.	
    Возвращаемое значение - код ошибки:
    0 - OK
    1 - ошибка конвертации
*/
int s21_floor(s21_decimal value, s21_decimal *result);

/*
    Округляет Decimal до ближайшего целого числа.	
    Возвращаемое значение - код ошибки:
    0 - OK
    1 - ошибка конвертации
*/
int s21_round(s21_decimal value, s21_decimal *result);

/*
    Возвращает целые цифры указанного Decimal числа;
    любые дробные цифры отбрасываются, включая конечные нули.	
    Возвращаемое значение - код ошибки:
    0 - OK
    1 - ошибка конвертации
*/
int s21_truncate(s21_decimal value, s21_decimal *result);

/*
    Возвращает результат умножения указанного Decimal на -1.	
    Возвращаемое значение - код ошибки:
    0 - OK
    1 - ошибка конвертации
*/
int s21_negate(s21_decimal value, s21_decimal *result);

//---------------------------------------------------------------------------
//-----------------------ДОПОЛНИТЕЛЬНЫЕ ФУНКЦИИ------------------------------
//---------------------------------------------------------------------------

/*
    Вывод на экран числа типа decemal
*/
void s21_print_decimal(s21_decimal dec);


#endif  // SRC_S21_DECEMAL_H_
