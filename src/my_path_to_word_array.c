/*
** EPITECH PROJECT, 2019
** fonction to save all the paths in my PATH env
** File description:
** for my minishell
*/

#include "my.h"

int my_count_space(char *str)
{
    int i = 0;
    int space = 0;

    while (str[i] != '\0') {
        if (str[i] == ':')
            space++;
        i++;
    }
    space += 1;
    return (space);
}

int my_len_word(char *str)
{
    int i = 0;

    while (str[i] && str[i] != ':') {
        i++;
    }
    return (i);
}

char *my_put_in_str(char *str, char *result)
{
    static int i = 0;
    int j = 0;

    while (str[i] && str[i] != ':') {
        result[j] = str[i];
        i++;
        j++;
    }
    result[j] = '\n';
    while (str[i] && str[i] == ':')
        i += 1;
    return (result);
}

char **my_path_to_word_array(char *str)
{
    int space = my_count_space(str);
    char **result = NULL;
    int k = 0;

    result = malloc(sizeof(char *) * my_strlen(str) * space);
    while (k != space) {
        result[k] = malloc(sizeof(char) * my_len_word(str) + 11);
        result[k] = my_put_in_str(str, result[k]);
        k++;
    }
    my_putstr(result[1]);
    free(result);
    return (result);
}