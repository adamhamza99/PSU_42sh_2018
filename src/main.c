/*
** EPITECH PROJECT, 2019
** main
** File description:
** 1
*/

#include "../include/my.h"

int exec(char *check, char **tab, char **env)
{
    pid_t pid;
    char *si;
    int sign;

    pid = fork();
    if (pid == 0) {
        bin(check, tab, env);
        exit(0);
    }
    if (waitpid(pid, &sign, 0)) {
        floating_exeption(sign, si);
    }
    return (0);
}

char *parse(char *s2, char **tab, char **env)
{
    char **tab_path = my_str_to_word_array(s2, ':');
    char *check;
    char *slash = "/";
    int a = 0;

    if (parse2(tab, env) == 1)
        return (NULL);
    while (tab_path[a] != NULL) {
        check = parse_concat(tab_path[a], slash, tab[0]);
        if (access(check, F_OK) == 0 || access(check, X_OK) == 0) {
            exec(check, tab, env);
            break;
        }
        a = a + 1;
    }
    if (tab_path[a] == NULL) {
        print_error(tab[0]);
        return (NULL);
    }
    return (NULL);
}

char *my_getenv(char **env, char **tab)
{
    int i = 0;
    static int count = 5;

    while (env[i] != NULL) {
        if (my_strncmp(env[i], "PATH=", count) == 0)
            copy(env[i], count, tab, env);
        i = i + 1;
    }
    return (env[i]);
}

char *create_historique(int choice)
{
    char c[4096];
    static char *history;
    int fd;

    if (choice == 1) {
        history = concat_params(getcwd(c, sizeof(c)), "/.42history");
        fd = open(history, O_RDONLY | O_APPEND);
        if (fd == -1) {
            fd = open(history, O_RDONLY | O_CREAT | O_APPEND);
        }
    }
    return (history);
}

int main(int argc, char **argv, char **env)
{
    char *str = NULL;
    char *s1 = NULL;
    char **tab = NULL;
    size_t size = 0;
    liste_t *liste = initialisation();
    int a = 0;

    while (env[a] != NULL) {
        insertion(liste, env[a]);
        a = a + 1;
    }
    create_historique(1);
    return (main_loop(argc, env, str, liste));
}
