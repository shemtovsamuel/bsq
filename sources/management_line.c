/*
** EPITECH PROJECT, 2020
** management_line.c
** File description:
** management_line.c
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/bsq.h"

int skip_first_line(int fd)
{
    char c = 0;

    while (c != '\n') {
        read(fd, &c, 1);
    }
    return (fd);
}

int counter_rows(char const *filepath)
{
    char c;
    int fd = open(filepath, O_RDONLY);
    fd = skip_first_line(fd);
    int count_rows = 0;

    while (read(fd, &c, 1) > 0) {
        if (c == '\n')
            count_rows++;
    }
    return (count_rows);
}

int counter_cols(char const *filepath)
{
    char c;
    int fd = open(filepath, O_RDONLY);
    fd = skip_first_line(fd);
    int count_cols = 0;

    while (read(fd, &c, 1) > 0) {
        count_cols++;
        if (c == '\n')
            return (count_cols);
    }
    return (0);
}