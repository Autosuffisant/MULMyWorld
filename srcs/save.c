/*
** EPITECH PROJECT, 2020
** my_world save
** File description:
** functions which will save the game
*/

#include "../include/engine.h"

int save_init(engine_t *en, int size)
{
    size_t char_size = sizeof(char);
    char *mode = "w";
    FILE *fp = fopen("./save/map", mode);

    if (fp == NULL) {
        my_putstr("File open error\n");
        return (84);
    }
    en->game.map[0][0][0] = en->game.map[0][0][0];
    fwrite(my_itoa(size), char_size, my_strlen(my_itoa(size)), fp);
    for (int i = 0; i != size; i++)
        for (int j = 0; j != size; j++)
            for (int k = 0; k != 5; k++) {
                fwrite(",", char_size, 1, fp);
                fwrite(my_itoa(en->game.map[i][j][k] + 50), char_size,
                my_strlen(my_itoa(en->game.map[i][j][k])), fp);
            }
    fclose(fp);
    return (0);
}