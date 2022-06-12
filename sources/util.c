/*
** EPITECH PROJECT, 2020
** util.c
** File description:
** util.c
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/bsq.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return (0);
}

int my_put_nbr(int nb)
{
    long int n;

    n = nb;
    if (n < 0) {
        my_putchar('-');
        n = -n;
    }
    if (n / 10)
        my_put_nbr(n / 10);
    my_putchar(n % 10 + '0');
    return (0);
}