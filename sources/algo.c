/*
** EPITECH PROJECT, 2020
** algo.c
** File description:
** algo.c
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/bsq.h"

int **in_algo(int **algo, int rows, int cols)
{
    for (int j = 0; j < rows; j++) {
        for (int i = 0; i < cols; i++) {
            algo[j][i] = 0;
        }
    }
    return (algo);
}

int **algo(char const *str, int rows, int cols)
{
    char **arr = str_to_2d(str, rows, cols);
    int **algo = mem_int_2d_array(rows, cols);

    algo = in_algo(algo, rows, cols);
    for (int j = 0; j < rows; j++) {
        for (int i = 0; i < cols - 1; i++) {
            if (arr[j][i] == 'o') {
                for (int a = j; a < rows; a++) {
                    for (int b = i; b < cols; b++) {
                        algo[a][b]++;
                   }
                }
            }
        }
    }
    return (algo);
}

int find_square(int **map, int i, int j, int s)
{
    if (i == 0 && j == 0 && (map[i + s][j + s] - map[i][j]
        - map[i][j] + map[i][j]) > 0)
        return (84);
    if (i == 0 && j > 0 && (map[i + s][j + s] - map[i + s][j - 1]
        - map[i][j] + map[i][j]) > 0)
        return (84);
    if (i > 0 && j == 0 && (map[i + s][j + s] - map[i][j]
        - map[i - 1][j + s] + map[i][j]) > 0)
        return (84);
    if (i > 0 && j > 0 && (map[i + s][j + s] - map[i + s][j - 1]
    - map[i - 1][j + s] + map[i - 1][j - 1]) > 0)
        return (84);
    return (0);
}