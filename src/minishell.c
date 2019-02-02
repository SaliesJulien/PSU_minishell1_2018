/*
** EPITECH PROJECT, 2019
** minishell 1
** File description:
** recode the terminal
*/
#include "my.h"

void fork_bin(char **env, char *str, char **new_str, char *path)
{
    pid_t pid;

    pid = fork();
    if (pid > 0)
        wait(0);
    else if (pid == 0) {
        execve(path, new_str, env);
    }
}

int find_path(char **env, char *str, char **new_str)
{
    char **path = NULL;
    char *elem = NULL;
    int k = 0;
    int i = 0;

    path = malloc(sizeof(char *) * 1000);
    elem = malloc(sizeof(char) * 1000);
    elem = my_getenv(env, elem);
    path = my_path_to_word_array(elem);
    while (path[k] != NULL) {
        my_strcat(path[k], "/");
        my_strcat(path[k], str);
        i = access(path[k], F_OK);
        if (i == 0) {
            fork_bin(env, str, new_str, path[k]);
            return (0);
        }
        k++;
    }
    free(elem);
    free(path);
}

void check_command(char **env, char *str, char **new_str)
{
    int i = 0;

    if (str[0] == 'e' && str[1] == 'n' && str[2] == 'v') {
        while (env[i] != NULL) {
            my_putstr(env[i]);
            my_putchar('\n');
            i++;
        }
    }
    else
        find_path(env, str, new_str);
}

int end_of_file(int eof, char *str)
{
    if (eof == -1) {
        my_putstr("\nexit");
        exit(0);
    }
    else if (str[0] == 'e' && str[1] == 'x' && str[2] == 'i' && str[3] == 't'
            && str[4] == '\n') {
        my_putstr("exit");
        exit(0);
    }
    else
        return (0);
}

int my_minishell(char **env)
{
    char *str = NULL;
    char **new_str = NULL;
    size_t len = 0;
    int eof = 0;
    int k = 0;

    str = malloc(sizeof(char *) * 1000);
    new_str = malloc(sizeof(char *) * 1000);
    while (42) {
        my_putstr("$>");
        eof = getline(&str, &len, stdin);
        end_of_file(eof, str);
        new_str = my_str_to_word_array(str, " ");
        check_command(env, str, new_str);
    }
}