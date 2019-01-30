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

char **my_str_to_word_array(char *str);
int my_strlen(char const *str);
int my_putnbr(int nb);
void my_putchar(char c);
char **my_path_to_word_array(char *str);
int my_putstr(char *str);
char **my_str_to_wordtab(char *str);

#endif