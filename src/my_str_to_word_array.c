/*
** EPITECH PROJECT, 2019
** my_str_to_word_array
** File description:
** take all word in a string
*/
#include "my.h"

int count_space(char *str)
{
    int i = 0;
    int space = 0;

    while (str[i] != '\0') {
        if (str[i] == ' ')
            space++;
        i++;
    }
    return (space);
}

int len_word(char *str)
{
    int i = 0;

    while (str[i] != ' ') {
        i++;
    }
    return (i);
}

char *put_in_str(char *str, char *result)
{
    static int i = 0;
    int j = 0;

    while (str[i] != ' ') {
        result[j] = str[i];
        i++;
        j++;
    }
    i += 1;
    return (result);
}

char **my_str_to_word_array(char *str)
{
    int space = count_space(str);
    int i = 0;
    char **result = NULL;
    int k = 0;
    int j = 0;

    result = malloc(sizeof(char *) * 1000);
    while (k != space + 1) {
        result[k] = malloc(sizeof(char) * len_word(str));
        result[k] = put_in_str(str, result[k]);
        k++;
    }
    free(result);
    return (result);
}