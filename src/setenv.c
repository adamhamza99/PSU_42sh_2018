/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** setenv
*/

#include "../include/my.h"

int error_setenv2(char **tab, liste_t *liste, char **env)
{
    if (tab[1] == NULL) {
        display(liste);
        return (0);
    }
    else if (sizeof_tab(tab) > 3) {
        write(1, "setenv: Too many arguments.\n", 28);
        return (0);
    }
}

int error_setenv(char **tab, liste_t *liste, char **env)
{
    error_setenv2(tab, liste, env);
    if (sizeof_tab(tab) == 3){
        if ((tab[1][0] < 'A' || tab[1][0] > 'Z') &&
            (tab[1][0] < 'a' || tab[1][0] > 'z')) {
            write(1, "setenv: Variable name must begin with a letter.\n", 48);
            return (0);
        }
        for (int count = 0; tab[2][count] != '\0';) {
            if (tab[2][count] == '_' || tab[2][count] == '=' ||
                (tab[2][count] >= 'A' && tab[2][count] <= 'Z') ||
                (tab[2][count] >= 'a' && tab[2][count] <= 'z')
                || (((tab[2][count] >= '1' && tab[2][count] <= '9'))))
                count++;
            else
                return (84);
        }
    }
    return (0);
}

int message_setenv(void)
{
    write(1, "setenv:", 7);
    write(1, " Variable name must contain alphanumeric characters.\n", 53);
    return (0);
}

int setenv_cmd(char **cmd_sh, liste_t *liste, char **env)
{
    element_t *set = liste->premier;
    char *add;
    if (sizeof_tab(cmd_sh) == 1) {
        display(liste);
        return (0);
    }
    add = concat_params(cmd_sh[1], "=");
    if (sizeof_tab(cmd_sh) == 3) {
        if (error_setenv(cmd_sh, liste, env) == 84)
            return (message_setenv());
        add = concat_params(add, cmd_sh[2]);
    }
    else if (sizeof_tab(cmd_sh) == 2) {
        insertion(liste, concat_params(cmd_sh[1], "="));
    }
    else {
        write(1, "setenv: Too many arguments.\n", 28);
        return (0);
    }
    insertion(liste, add);
    return (0);
}

int builtins(char **tab, liste_t *liste, char **env)
{
    if (my_strncmp(tab[0], "setenv", my_strlen(tab[0])) == 0)
        return (setenv_cmd(tab, liste, env));
    if (my_strncmp(tab[0], "env", my_strlen(tab[0])) == 0) {
        display(liste);
        return (0);
    }
    if (my_strncmp(tab[0], "cd", my_strlen(tab[0])) == 0)
        return (cd_cmd(tab, liste));
    return (1);
}
