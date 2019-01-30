/*
** EPITECH PROJECT, 2019
** minishell 1
** File description:
** recode the terminal
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

int my_minishell(char **env)
{
    char *str = NULL;
    size_t len = 0;
    char *elem = NULL;
    int eof = 0;

    elem = malloc(sizeof(char *) * 100);
    while (42) {
        my_putstr("$>");
        eof = getline(&str, &len, stdin);
        if (eof == -1) {
            my_putstr("\nexit");
            return (0);
        }
        elem = my_getenv(env, elem);
        my_path_to_word_array(elem);
        }
    free(elem);
}

int main(int ac, char **av, char **env)
{
    my_minishell(env);
}

//PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin:/home/J.Salies/.local/bin:/home/J.Salies/bin