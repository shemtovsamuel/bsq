/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main.c
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/bsq.h"

int display_map(char **map, int backup_x, int backup_y, int backup_size, char *filepath)
{
    char const *str = filepath;
    int cols = counter_cols(str);
    int rows = counter_rows(str);

    for (int y = backup_y; y < backup_y + backup_size; y++) {
        for (int x = backup_x ; x < backup_x + backup_size; x++) {
            map[y][x] = 'x';
        }
    }

    for (int j = 0; j < rows; j++) {
        for (int i = 0; i < cols - 1; i++) {
            my_putchar(map[j][i]);
        }
        my_putchar('\n');
    }
    return (0);
}

int *result_algo(int rows, int cols, char **char_map, int **arr)
{
    int *tab = malloc(sizeof(int) * 5);

    for (int y = 0; y < rows - tab[0]; y++)
        for (int x = 0; x < cols - tab[0]; x++) {
            tab[0] = 0;
            tab[4] = 0;
            if (char_map[y][x] == '.') {
                while (tab[4] != 84) {
                    tab[0] ++;
                    if (y + tab[0] > rows || x + tab[0] > cols)
                        break;
                    tab[4] = find_square(arr, y, x, tab[0]);
                }
                if (tab[0] > tab[1]) {
                    tab[1] = tab[0];
                    tab[2] = x;
                    tab[3] = y;
                }
            }
        }
    return (tab);
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return(84);

    char const *str = argv[1];
    int cols = counter_cols(str);
    int rows = counter_rows(str);
    int **arr = algo(map_to_str(str), rows, cols);
    char **char_map =  str_to_2d(map_to_str(str), rows, cols);
    int *tab = result_algo(rows, cols, char_map, arr);
    char **display = str_to_2d(map_to_str(str), rows, cols);

    display_map(display, tab[2], tab[3], tab[1], argv[1]);
    return (0);
}