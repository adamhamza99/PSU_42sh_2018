/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** promp
*/

#include "../include/my.h"

void my_prompt(char **env)
{
    if (isatty(0) == 1) {
        my_printf("\033[4;34m%s\033[0m", get_user(env));
        my_printf("\033[1;37m:\033[0m");
        my_printf("\033[1;31m%s\033[0m", get_current_directory(env));
        my_printf("> ");
    }
}

char *get_current_directory(char **env)
{
    char c[4096];
    char *str = NULL;

    str = getcwd(c, sizeof(c));
    return(str);
}

char *get_user(char **env)
{
    for (int count = 0; env[count]; count++)
        if (my_strncmp(env[count], "USER=", 5) == 0)
            return (env[count] + 5);
    return ("user");
}
