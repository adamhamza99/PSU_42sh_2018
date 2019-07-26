/*
** EPITECH PROJECT, 2018
** 11
** File description:
** 1
*/

#ifndef _MY_H_
#define _MY_H_
#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <fcntl.h>

typedef struct info_s
{
    char ** my_env;

}info_t;

typedef struct element_s element_t;
typedef struct element_s
{
    char *str;
    element_t *suivant;
}element_t;

typedef struct liste_s liste_t;
typedef struct liste_s
{
    element_t *premier;
}liste_t;

typedef struct funct_s {
    void (*ptr)(va_list);
    char letter;
}funct_t;

char *parse_concat(char *tab_path, char *slash, char *tab);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *ends(char *s2);
int print_error(char *s);
int cd_check(char *s);
int cd_error1(char *s);
int cd_error2(char *s);
char *copy(char *s1, int count, char **tab, char **env);
int exec(char *str, char **tab, char **env);
char *concat_params(char *s2, char *s1);
char *parse(char *s2, char **tab, char **env);
char *debut(char *s1);
int parse2(char **tab, char **env);
int bin(char *check, char **tab, char **env);
char *my_getenv(char **env, char **tab);
char *spaces(char *s1);
char *spaces2(char *s2);
char *tab(char *s1);
char **my_str_to_word_array(char *str, char c);
int cd(char **tab);
void my_putchar(char c);
void display(liste_t *liste);
void suppression(liste_t *liste);
void insertion(liste_t *liste, char *nvStr);
liste_t *initialisation(void);
int sizeof_tab(char **array);
int show(char **tab);
int error_setenv(char **tab, liste_t *liste, char **env);
int setenv_cmd(char **cmd_sh, liste_t *liste, char **env);
void my_printf(char *s, ...);
void search_array(char c, va_list ap);
void modulo_s(va_list ap);
int builtins(char **cmd_sh, liste_t *liste, char **env);
int cd_basic(char **cmd_sh, liste_t *liste, DIR *dir);
int cd_cmd(char **cmd_sh, liste_t *liste);
int main_loop(int argc, char **env, char *str, liste_t *liste);
int floating_exeption(int sign, char *si);
int message_setenv(void);
char *remove_separator(char *s1);
int do_separator(char *str, int count, char **env);
int separator(char *str, char **env);
char *create_historique(int choice);
void my_prompt(char **env);
char *get_current_directory(char **env);
char *get_user(char **env);
void ctrl_c(int a);
#endif
