/*
** EPITECH PROJECT, 2019
** my_str_to_word_array
** File description:
** take all word in a string
*/
#include "my.h"


bool is_sep(char c, char *sep)
{
    int i = 0;

    for (i = 0; c != sep[i] && sep[i]; i++);
    return (c == sep[i]);
}

int count_space(char *str, char *sep)
{
    int i = 0;
    int space = 1;

    while (str[i] != '\0') {
        if (str[i] == sep[0])
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

char *put_in_str(char *str, char *result, char *sep)
{
    static int i = 0;
    int j = 0;

    while (str[i] && !is_sep(str[i], sep)) {
        result[j] = str[i];
        i++;
        j++;
    }
    while (str[i] && is_sep(str[i], sep))
        i += 1;
    return (result);
}

int check_str(char *str, char *sep)
{
    int count = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == sep[0])
            count++;
        i++;
    }
    return (count);
}

char **my_str_to_word_array(char *str, char *sep)
{
    int space = count_space(str, sep);
    char **result = NULL;
    int k = 0;
    int count = 0;

    result = malloc(sizeof(char *) * my_strlen(str));
    count = check_str(str, sep);
    if (count == 0) {
        result[0] = str;
        return (result);
    }
    else {
        while (k != space) {
            result[k] = malloc(sizeof(char) * len_word(str));
            result[k] = put_in_str(str, result[k], sep);
            k++;
        }
        result[k] = NULL;
        return (result);
    }
}