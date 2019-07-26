/*
** EPITECH PROJECT, 2019
** my_strncmp
** File description:
** 1
*/

#include "../include/my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int a = 0;

    while (n != 0) {
        if (s1[a] == s2[a]) {
            a = a + 1;
        }
        else {
            return (1);
        }
        n--;
    }
    return (0);
}

char *copy(char *s1, int count, char **tab, char **env)
{
    int i = count;
    int e = 0;
    char *s2 = malloc(sizeof(char) * (my_strlen(s1) - 4));

    while (s1[i] != '\0') {
        s2[e] = s1[i];
        e = e + 1;
        i = i + 1;
    }
    s2[e] = '\0';
    parse(s2, tab, env);
    return (s2);
}