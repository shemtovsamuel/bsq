/*
** EPITECH PROJECT, 2020
** management.c
** File description:
** management.c
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/bsq.h"

char **mem_char_2d_array(int rows, int cols)
{
    char **arr = malloc(sizeof(char *) * rows);

    if (arr == NULL)
        return (NULL);
    for (int i = 0; i < cols; i++) {
        arr[i] = malloc(sizeof(char) * cols);
        if (arr == NULL)
            return (NULL);
    }
    return (arr);
}

int **mem_int_2d_array(int rows, int cols)
{
    int **arr = malloc(sizeof(int *) * rows);

    if (arr == NULL)
        return (NULL);
    for (int i = 0; i < cols; i++) {
        arr[i] = malloc(sizeof(int) * cols);
        if (arr == NULL)
            return (NULL);
    }
    return (arr);
}

char *map_to_str(char const *filepath)
{
    char c = 0;
    int fd = open(filepath, O_RDONLY);
    fd = skip_first_line(fd);
    struct stat buff;
    stat(filepath, &buff);
    char *str = malloc(sizeof(char *) * buff.st_size);
    int i = 0;

    while (read(fd, &c, 1) > 0) {
        str[i] = c;
        i++;
    }
    return (str);
}

char **str_to_2d(char const *str, int rows, int cols)
{
    int i_str = 0;
    char **arr = mem_char_2d_array(rows, cols);

    for (int j = 0; j < rows; j++) {
        for (int i = 0; i < cols; i++) {
            arr[j][i] = str[i_str];
            i_str++;
        }
    }
    return (arr);
}