/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** struct
*/

#include "../include/my.h"

liste_t *initialisation(void)
{
    liste_t *liste = malloc(sizeof(*liste));
    element_t *element = malloc(sizeof(*element));

    if (liste == NULL || element == NULL)
        exit(84);
    liste->premier = element;
    return (liste);
}

void insertion(liste_t *liste, char *nvStr)
{
    element_t *nouveau = malloc(sizeof(*nouveau));

    if (liste == NULL || nouveau == NULL)
        exit(84);
    nouveau->str = nvStr;
    nouveau->suivant = liste->premier;
    liste->premier = nouveau;
}

void suppression(liste_t *liste)
{
    element_t *aSupprimer = liste->premier;

    if (liste == NULL)
        exit(84);
    if (liste->premier != NULL) {
        liste->premier = liste->premier->suivant;
        free(aSupprimer);
    }
}

void display(liste_t *liste)
{
    element_t *actuel = liste->premier;
    if (liste == NULL)
        exit(84);
    while (actuel->suivant != NULL) {
        my_printf("%s\n", actuel->str);
        actuel = actuel->suivant;
    }
}