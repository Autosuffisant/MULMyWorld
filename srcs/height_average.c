/*
** EPITECH PROJECT, 2020
** world height average
** File description:
** tool to average the height in my_world
*/

#include "../include/engine.h"

int get_height_average(engine_t *en, sfVector2f pos, sfVector2i mouse, int h)
{
    int raise = 0;

    if (pos.x < mouse.x + en->game.scale &&
        pos.x > mouse.x - en->game.scale)
        if (pos.y < mouse.y + en->game.scale &&
            pos.y > mouse.y - en->game.scale)
            raise = h;
    return (raise);
}

int is_averaged(engine_t *en, sfVector2f pos, sfVector2i mouse)
{
    int raise = 0;

    if (pos.x < mouse.x + en->game.scale &&
        pos.x > mouse.x - en->game.scale)
        if (pos.y < mouse.y + en->game.scale &&
            pos.y > mouse.y - en->game.scale)
            raise = 1;
    return (raise);
}

int apply_average(int is, int height, int average)
{
    int applied = height;

    if (is == 0)
        return (height);
    if (height < average)
        return (applied + 1);
    if (height > average)
        return (applied - 1);
    return (height);
}

void map_apply_average(engine_t *en, int av_value, int av_got, sfVector2i pos)
{
    av_value = av_value / av_got;
    for (int a = 0; a != en->game.map_size; a++)
        for (int b = 0; b != en->game.map_size; b++)
            for (int c = 0; c != 5; c++) {
                av_got = is_averaged(en, en->game.positions[a][b][c], pos);
                en->game.map[a][b][c] = apply_average(av_got,
                en->game.map[a][b][c], av_value);
            }
}

void height_average_check(engine_t *en)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(en->graphics.window);
    int av_got = 0;
    int av_value = 0;

    for (int i = 0; i != en->game.map_size; i++)
        for (int j = 0; j != en->game.map_size; j++)
            for (int k = 0; k != 5; k++) {
                av_got += is_averaged(en, en->game.positions[i][j][k],
                pos);
                av_value += get_height_average(en, en->game.positions[i][j][k]
                , pos, en->game.map[i][j][k]);
            }
    if (av_got == 0)
        return;
    map_apply_average(en, av_value, av_got, pos);
}