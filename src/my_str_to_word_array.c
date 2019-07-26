/*
** EPITECH PROJECT, 2018
** str word array
** File description:
** 1
*/

#include "../include/my.h"

int nb_col(char *str, int i, char c)
{
    int a = 0;

    while (str[i] != c && str[i] != '\0') {
        a = a + 1;
        i = i + 1;
    }
    return (a);
}

int nb_line(char *str, char c)
{
    int i = 0;
    int count = 1;

    while (str[i] != '\0') {
        if (str[i] == c)
            count = count + 1;
        i = i + 1;
    }
    return (count);
}

char *my_copy(char *desk, char *str, int i, char c)
{
    int a = 0;

    while (str[i] != c && str[i]) {
        desk[a] = str[i];
        a = a + 1;
        i = i + 1;
    }
    desk[a] = '\0';
    return (desk);
}

char **my_str_to_word_array(char *str, char c)
{
    int i = 0;
    int a = 0;
    char **tab;

    tab = malloc(sizeof(char *) * (nb_line(str, c) + 1));
    while (str[i++] != '\0') {
        if (a == 0)
            i = 0;
        tab[a] = malloc(sizeof(char *) * (nb_col(str, i, c) + 1));
        my_copy(tab[a], str, i, c);
        while (str[i] != c && str[i])
            i = i + 1;
        if (str[i] == c || str[i] == '\0')
            a = a + 1;
    }
    tab[a] = NULL;
    return (tab);
}
