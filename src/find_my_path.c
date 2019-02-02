/*
** EPITECH PROJECT, 2019
** minishell 1
** File description:
** fonction to find my path
*/

#include "my.h"

void draw_my_env(char **env)
{
    int k = 0;

    while (env[k] != 0) {
        my_putstr(env[k]);
        k++;
    }
}

char *my_getenv(char **env, char *elem)
{
    int k = 0;
    int j = 5;
    int i = 0;

    while (env[k] != NULL) {
        if (env[k][0] == 'P' && env[k][1] == 'A' && env[k][2] == 'T' && 
            env[k][3] == 'H' && env[k][4] == '=') {
            while (env[k][j] != '\0') {
                elem[i] = env[k][j];
                j++;
                i++;
            }
        }
        k++;
    }
    elem[i] = '\0';
    return (elem);
}