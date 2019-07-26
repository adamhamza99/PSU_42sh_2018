/*
** EPITECH PROJECT, 2018
** oi
** File description:
** ekhcb
*/

#include "../include/my.h"

int my_strlen(char const *str)
{
    int len;

    len = 0;
    while (str[len] != '\0') {
        len = len + 1;
    }
    return (len);
}
