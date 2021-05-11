/*
** EPITECH PROJECT, 2020
** world map reset
** File description:
** function dedicated to the map's heights reset
*/

#include "../include/engine.h"

int heights_reset(engine_t *en)
{
    for (int i = 0; i != en->game.map_size; i++)
        for (int j = 0; j != en->game.map_size; j++)
            for (int k = 0; k != 5; k++)
                en->game.map[i][j][k] = 0;
    return (0);
}