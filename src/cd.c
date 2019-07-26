/*
** EPITECH PROJECT, 2019
** cd
** File description:
** 1
*/

#include "../include/my.h"

int my_strlentab(char **tab)
{
    int i = 0;

    while (tab[i]) {
        i = i + 1;
    }
    return (i);
}

int cd_check(char *s)
{
    DIR* dir = opendir(s);

    if (access(s, F_OK) != -1) {
        if (dir) {
            closedir(dir);
        }
        if (ENOTDIR == errno) {
            return (84);
        }
    }
    else {
        return (1);
    }
    return (0);
}

int cd_basic(char **cmd_sh, liste_t *liste, DIR *dir)
{
    struct stat stt;
    char c[1000];
    static char *oldpwd = "\0";
    char *way;

    stat(cmd_sh[1], &stt);
    if (cmd_sh[1][0] == '-' && cmd_sh[1][1] == '\0') {
        way = concat_params(oldpwd, "\0");
        oldpwd = getcwd(c, sizeof(c));
        chdir(way);
        return (0);
    }
    if (dir == NULL) {
        if (S_ISDIR(stt.st_mode) == 0)
            return (cd_error2(cmd_sh[1]));
        cd_error1(cmd_sh[1]);
        return (0);
    }
    oldpwd = getcwd(c, sizeof(c));
    chdir(cmd_sh[1]);
}

int cd_cmd(char **cmd_sh, liste_t *liste)
{
    DIR *dir;

    if (sizeof_tab(cmd_sh) == 1)
        chdir("/home");
    if (sizeof_tab(cmd_sh) == 2) {
        dir = opendir(cmd_sh[1]);
        if (my_strcmp(cmd_sh[1], "--") == 0)
            chdir("/home");
        else if (my_strncmp(cmd_sh[1], "~", my_strlen(cmd_sh[1])) == 0)
            chdir("/home");
        else
            cd_basic(cmd_sh, liste, dir);
    }
    else {
        my_putstr("cd: Too many arguments.\n");
    }
    return (0);
}
