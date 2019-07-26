/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** my_printf
*/


#include "../include/my.h"

static funct_t tableau_g[] =
{
    {&modulo_s, 's'},
    {0, 0}
};

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_printf(char *s, ...)
{
    int i = 0;
    va_list ap;
    va_start(ap, s);
    while (s[i] != '\0') {
        if (s[i] == '%') {
            i = i + 1;
            search_array(s[i], ap);
            i = i + 1;
        }
        if (s[i] != '%') {
            my_putchar(s[i]);
        }
        i++;
    }
}

void search_array(char c, va_list ap)
{
    int i = 0;

    while (tableau_g[i].letter != '\0'){
        if (c == tableau_g[i].letter)
            tableau_g[i].ptr(ap);
        i++;
    }
}
