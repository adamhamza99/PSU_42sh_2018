/*
** EPITECH PROJECT, 2019
** main
** File description:
** 3
*/

#include "../include/my.h"

int floating_exeption(int sign, char *si)
{
    if (WIFSIGNALED(sign)) {
        si = strsignal(WTERMSIG(sign));
        if ((my_strcmp("Floating point exception", si)) == 0)
            si = "Floating exception";
        my_putstr(si);
        my_putstr("\n");
    }
    return (0);
}
