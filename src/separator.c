/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** separator
*/

#include "../include/my.h"

char *remove_separator(char *s1)
{
    int i = 0;
    int a = 0;
    char *s2 = malloc(sizeof(char) * (my_strlen(s1) + 1));

    tab(s1);
    while (s1[i] == ';') {
        i = i + 1;
    }
    while (s1[i] != '\0') {
        if (s1[i] != ';')
            s2[a++] = s1[i++];
        if (s1[i] == ';' && s1[i + 1] == ';')
            i = i + 1;
        if (s1[i] == ';' && s1[i + 1] != ';')
            s2[a++] = s1[i++];
    }
    ends (s2);
    return (s2);
}

int do_separator(char *str, int count, char **env)
{
    char **tab = my_str_to_word_array(str, ';');
    char **sep = NULL;
    int i = 0;

    while (tab[i] != NULL) {
        sep = my_str_to_word_array(tab[i], ' ');
        my_getenv(env, sep);
        i++;
    }
    return (0);
}

int separator(char *str, char **env)
{
    int i = 0;
    int count = 0;

    str = remove_separator(str);
    while (str[i] != '\0') {
        if (str[i] == ';')
            count = count + 1;
        i++;
    }
    if (count > 0)
        return (do_separator(str, count, env));
    return (84);
}
