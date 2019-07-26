/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** modulo_s
*/

#include "../include/my.h"

void modulo_s(va_list ap)
{
    my_putstr(va_arg(ap, char *));
}