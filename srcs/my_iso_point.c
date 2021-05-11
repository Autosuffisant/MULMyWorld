/*
** EPITECH PROJECT, 2020
** suus
** File description:
** suus
*/

#include "../include/engine.h"

sfVector2f project_iso_point(sfVector2f pos, int height)
{
    sfVector2f snd_point;
    sfVector3f thd_point;

    thd_point.x = pos.x;
    thd_point.y = pos.y;
    thd_point.z = height;
    snd_point.x = cos(0.785398) * thd_point.x - cos(0.785398) * thd_point.y;
    snd_point.y = sin(0.610865) * thd_point.y + sin(0.610865) * thd_point.x -
    thd_point.z;
    return (snd_point);
}

int set_map_to_3d(engine_t *en, int size)
{
    for (int i = 0; i != size; i++)
        for (int j = 0; j != size; j++) {
            for (int k = 0; k != 5; k++) {
                en->game.positions[i][j][k] =
                project_iso_point(en->game.positions[i][j][k],
                en->game.map[i][j][k]);
                }
        }
    return (0);
}

int map_center(engine_t *en, int size)
{
    sfVector2f map_center;
    sfVector2u screen_center = sfRenderWindow_getSize(en->graphics.window);

    map_center.y = en->game.positions[size-1][0][0].y;
    map_center.x = en->game.positions[0][0][0].x;
    map_center.x = screen_center.x / 2 - map_center.x;
    map_center.y = map_center.y - screen_center.y / 2;
    for (int i = 0; i != size; i++)
        for (int j = 0; j != size; j++)
            for (int k = 0; k != 5; k++) {
                en->game.positions[i][j][k].x += map_center.x;
                en->game.positions[i][j][k].y -= map_center.y;
                }
    return (0);
}

int camera_center(engine_t *en, int size)
{
    sfVector2f map_center = en->game.positions[size/2][size/2][0];

    sfView_setCenter(en->graphics.view, map_center);
    return (0);
}