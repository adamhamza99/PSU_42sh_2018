/*
** EPITECH PROJECT, 2019
** error
** File description:
** print
*/

#include "../include/my.h"

int print_error(char *s)
{
    my_putstr(s);
    my_putstr(": Command not found.\n");
    return (0);
}

int cd_error1(char *s)
{
    my_putstr(s);
    my_putstr(": No such a file or directory.\n");
    return (0);
}

int cd_error2(char *s)
{
    my_putstr(s);
    my_putstr(": Not a directory.\n");
    return (0);
}