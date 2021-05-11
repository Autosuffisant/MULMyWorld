/*
** EPITECH PROJECT, 2020
** world height change
** File description:
** change the map height in my_world
*/

#include "../include/engine.h"

int lower_vertex(sfVector2f pos, sfVector2i mousepos, int height, int scale)
{
    int raise = 0;

    if (height < -40)
        return (raise);
    if (mousepos.x < pos.x + scale / 2 &&
        mousepos.x > pos.x - scale / 2)
        if (mousepos.y < pos.y + scale / 2 &&
            mousepos.y > pos.y - scale / 2)
            raise = 1;
    return (raise);
}

int raise_vertex(sfVector2f pos, sfVector2i mousepos, int height, int scale)
{
    int raise = 0;

    if (height >= 40)
        return (raise);
    if (mousepos.x < pos.x + scale / 2 &&
        mousepos.x > pos.x - scale / 2)
        if (mousepos.y < pos.y + scale / 2 &&
            mousepos.y > pos.y - scale / 2)
            raise = 1;
    return (raise);
}

void max_heights(engine_t *en, int x, int y, int z)
{
    if (en->game.map[x][y][z] < -40)
        en->game.map[x][y][z] = -40;
    if (en->game.map[x][y][z] > 40)
        en->game.map[x][y][z] = 40;
}

int lower_vertex_check(engine_t *en, int size)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(en->graphics.window);
    sfVector2f sent;
    int scale = en->game.scale;
    int gap = 0;

    for (int i = 0; i != size; i++)
        for (int j = 0; j != size; j++)
            for (int k = 0; k != 5; k++) {
                sent.x = en->game.positions[i][j][k].x;
                sent.y = en->game.positions[i][j][k].y
                + en->game.map[i][j][k];
                max_heights(en, i, j, k);
                gap = en->game.map[i][j][k];
                gap = lower_vertex(sent, pos,
                gap, scale);
                en->game.map[i][j][k] -= gap;
            }
    return (0);
}

int raise_vertex_check(engine_t *en, int size)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(en->graphics.window);
    sfVector2f sent;
    int scale = en->game.scale;
    int gap = 0;

    for (int i = 0; i != size; i++)
        for (int j = 0; j != size; j++)
            for (int k = 0; k != 5; k++) {
                sent.x = en->game.positions[i][j][k].x;
                sent.y = en->game.positions[i][j][k].y
                + en->game.map[i][j][k];
                max_heights(en, i, j, k);
                gap = en->game.map[i][j][k];
                gap = raise_vertex(sent, pos,
                gap, scale);
                en->game.map[i][j][k] += gap;
            }
    return (0);
}