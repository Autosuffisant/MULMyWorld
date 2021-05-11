/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** update coordinates
*/

#include "../include/engine.h"

void update_vertex_array(engine_t *en, int a, int i, int j)
{
    sfVertex point;
    int gap = 50;

    sfVertexArray_clear(en->game.vertex_tab[a][i][j]);
    for (int k = 0; k != 5; k++) {
        point.color =
        sfColor_fromRGB(216, 168 + en->game.map[i][j][k], 32);
        if (a == 1)
            point.color = sfBlack;
        point.position.x = en->game.positions[i][j][k].x
        - ((en->game.map_size * gap) / 8) + gap;
        point.position.y = (en->game.positions[i][j][k].y
        - ((en->game.map_size * gap) / 8) + gap - (en->game.map[i][j][k]
        * (en->game.scale / 100)));
        sfVertexArray_append(en->game.vertex_tab[a][i][j], point);
    }
}

void update_map_coordinates(engine_t *en)
{
    for (int a = 0; a != 2; a++)
        for (int i = 0; i != en->game.map_size; i++)
            for (int j = 0; j != en->game.map_size; j++)
                update_vertex_array(en, a, i, j);
}