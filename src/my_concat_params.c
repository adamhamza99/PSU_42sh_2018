/*
** EPITECH PROJECT, 2019
** my_concat_params
** File description:
** 1
*/

#include "../include/my.h"

char *concat_params(char *s1, char *s2)
{
    int i = 0;
    int a = 0;
    int b = 0;
    char *str = malloc(sizeof(char) * ((my_strlen(s1)) + (my_strlen(s2)) + 1));

    while (s1[a] != '\0') {
        str[i] = s1[a];
        i = i + 1;
        a = a + 1;
    }
    while (s2[b] != '\0') {
        str[i] = s2[b];
        i = i + 1;
        b = b + 1;
    }
    str[i] = '\0';
    return (str);
}

int show(char **tab)
{
    int a = 0;

    while (tab[a] != NULL) {
        my_putstr(tab[a]);
        my_putstr("\n");
        a++;
    }
    return (0);
}

int sizeof_tab(char **array)
{
    int a = 0;

    while (array[a] != NULL)
        a = a + 1;
    return (a);
}