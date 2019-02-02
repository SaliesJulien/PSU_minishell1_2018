/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** minishell
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>

#ifndef MY_H
#define MY_H

char **my_str_to_word_array(char *str, char *sep);
int my_strlen(char const *str);
int my_putnbr(int nb);
char *my_strcat(char *dest, char *src);
void my_putchar(char c);
int my_minishell(char **env);
void draw_my_env(char **env);
char *my_getenv(char **env, char *elem);
char **my_path_to_word_array(char *str);
int my_putstr(char *str);
char **my_str_to_wordtab(char *str);

#endif