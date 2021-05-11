/*
** EPITECH PROJECT, 2020
** world colors
** File description:
** color handling functions of the world
*/

#include "../include/engine.h"

int check_color_change(engine_t *en, int size, int color_id)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(en->graphics.window);
    int scale = en->game.scale;

    for (int i = 0; i != size; i++)
        for (int j = 0; j != size; j++)
            for (int k = 0; k != 5; k++)
                raise_vertex(en->game.positions[i][j][k], pos, scale);
    return (0);
}