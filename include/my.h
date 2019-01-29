/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** minishell
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef MY_H
#define MY_H

int my_strlen(char const *str);
int my_putnbr(int nb);
void my_putchar(char c);
int my_putstr(char *str);
char **my_str_to_wordtab(char *str);

#endif