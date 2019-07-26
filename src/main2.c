/*
** EPITECH PROJECT, 2019
** main2
** File description:
** 2
*/

#include "../include/my.h"

char *parse_concat(char *tab_path, char *slash, char *tab)
{
    char *check;
    char *cmd;
    cmd = concat_params(tab_path, slash);
    check = concat_params(cmd, tab);
    return (check);
}

int parse2(char **tab, char **env)
{
    if (access(tab[0], F_OK) == 0 || access(tab[0], X_OK) == 0) {
        exec(tab[0], tab, env);
        return (1);
    }
    return (0);
}

int permission_denied(char *check)
{
    struct stat size;

    stat(check, &size);
    if (S_ISDIR(size.st_mode) == 1) {
        my_putstr(check);
        my_putstr(": Permission denied.\n");
        return (84);
    }
    return (0);
}

int bin(char *check, char **tab, char **env)
{
    if (permission_denied(check) == 84)
        return (0);
    if ((execve(check, tab, env) == -1)) {
        my_putstr(check);
        my_putstr(": Exec format error. Wrong Architecture.\n");
    }
    else
        execve(check, tab, env);
    return (0);
}

int main_loop(int argc, char **env, char *str, liste_t *liste)
{
    char *s1 = NULL;
    size_t size = 0;
    char **tab = NULL;

    while (1) {
        my_prompt(env);
        argc = getline(&str, &size, stdin);
        if (argc == -1 || my_strcmp(str, "exit\n") == 0)
            exit(0);
        if (str[my_strlen(str) - 1] == '\n')
            str[my_strlen(str) - 1] = '\0';
        if (my_strncmp("\0", str, 1) == 0)
            continue;
        s1 = spaces(str);
        if (separator(str, env) == 0)
            continue;
        tab = my_str_to_word_array(s1, ' ');
        if (builtins(tab, liste, env) == 0)
            continue;
        my_getenv(env, tab);
    }
}
