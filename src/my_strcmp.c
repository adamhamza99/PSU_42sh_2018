/*
** EPITECH PROJECT, 2019
** my_strcmp.c
** File description:
** 1
*/

#include "../include/my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int a = 0;

    while (s1[a] != '\0' && s2[a] != '\0' && s1[a] - s2[a] == 0) {
        a = a + 1;
    }
    return (s1[a] - s2[a]);
}
