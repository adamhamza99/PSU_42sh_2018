/*
** EPITECH PROJECT, 2019
** epur
** File description:
** space
*/

#include "../include/my.h"

int fill_history(char *s1)
{
    char *history = create_historique(0);
    int fd = open(history, O_RDWR | O_APPEND);
    static int i = 1;

    s1 = concat_params("\n", s1);
    write(fd, s1, my_strlen(s1));
    return (0);
}

char *spaces(char *s1)
{
    int i = 0;
    int a = 0;
    char *s2 = malloc(sizeof(char) * (my_strlen(s1) + 1));

    fill_history(s1);
    tab(s1);
    while (s1[i] == ' ') {
        i = i + 1;
    }
    while (s1[i] != '\0') {
        if (s1[i] != ' ')
            s2[a++] = s1[i++];
        if (s1[i] == ' ' && s1[i + 1] == ' ')
            i = i + 1;
        if (s1[i] == ' ' && s1[i + 1] != ' ')
            s2[a++] = s1[i++];
    }
    ends(s2);
    return (s2);
}

char *ends(char *s2)
{
    if (s2[my_strlen(s2) - 1] == ' ' || s2[my_strlen(s2) - 1] == ';')
        s2[my_strlen(s2) - 1] = '\0';
    return (s2);
}

char *tab(char *s1)
{
    int i = 0;
    while (s1[i] != '\0') {
        if (s1[i] == '\t')
            s1[i] = ' ';
        i++;
    }
    return (s1);
}
