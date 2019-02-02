/*
** EPITECH PROJECT, 2018
** my_strcat
** File description:
** oui
*/
#include "../../include/my.h"

char *my_strcat(char *dest, char *src)
{
    int i = 0;
    int len = my_strlen(dest);
    
    while (src[i] != '\n') {
	    dest[i + len] = src[i];
	    i++;
    }
    dest[i + len] = '\0';
    return (dest);
}
