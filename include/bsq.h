/*
** EPITECH PROJECT, 2020
** bsq.h
** File description:
** bsq.h
*/

#include <stdarg.h>

#ifndef PRINTF_H_
#define PRINTF_H_

void my_putchar(char c);
int my_putstr(char const *str);
int my_put_nbr(int nb);
int skip_first_line(int fd);
int counter_rows(char const *filepath);
int counter_cols(char const *filepath);
char **mem_char_2d_array(int rows, int cols);
int **mem_int_2d_array(int rows, int cols);
char *map_to_str(char const *filepath);
char **str_to_2d(char const *str, int rows, int cols);
int **initialization_algo(int **algo, int rows, int cols);
int **algo(char const *str, int rows, int cols);
int find_square(int **map, int i, int j, int s);
int display_map(char **map, int backup_x, int backup_y,
                int backup_size, char *filepath);

#endif