/*
** EPITECH PROJECT, 2022
** printf header
** File description:
** SE
*/


#ifndef PRINTF_H_
    #define PRINTF_H_

    #include <stdarg.h>

    typedef struct cases {
        char flag;
        void (*f)(va_list);
    } cases_t;

    void printf_address(va_list av);
    void printf_bin(va_list av);
    void printf_char(va_list av);
    void printf_hex_l(va_list av);
    void printf_hex_u(va_list av);
    void printf_int(va_list av);
    void printf_oct(va_list av);
    void printf_per(va_list av);
    void printf_print(va_list av);
    void printf_str(va_list av);
    void printf_uint(va_list av);

#endif
