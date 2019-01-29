/*
** EPITECH PROJECT, 2019
** minishell 1
** File description:
** recode the terminal
*/
#include "my.h"

char *my_getenv(char **env, char *elem)
{

}

int my_minishell(void)
{
    char *str = NULL;
    size_t len = 0;

    while (42) {
        my_putstr("$>");
        getline(&str, &len, stdin);
    }
}

int main(int ac, char **av, char **env)
{
    my_minishell();
}