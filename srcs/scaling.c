/*
** EPITECH PROJECT, 2020
** world scaling
** File description:
** functions to change the scaling for the my_world project
*/

#include "../include/engine.h"

sfVector2f get_middle(sfVector2f up_middle, sfVector2f bot_middle, int size)
{
    sfVector2f true_middle;

    if (size % 2 == 0) {
        true_middle = up_middle;
        return (true_middle);
    }
    true_middle.x = (up_middle.x + bot_middle.x) / 2;
    true_middle.y = (up_middle.y + bot_middle.y) / 2;
    return (true_middle);
}

void scale_down(engine_t *en, int size)
{
    sfVector2f center = get_middle(en->game.positions[size/2][size/2][0],
    en->game.positions[size/2][size/2][2], size);
    sfVector2f new_center;

    for (int i = 0; i != size; i++)
        for (int j = 0; j != size; j++)
            for (int k = 0; k != 5; k++) {
                en->game.positions[i][j][k].x *= (1/1.04f);
                en->game.positions[i][j][k].y *= (1/1.04f);
            }
    new_center = get_middle(en->game.positions[size/2][(size/2)][0],
    en->game.positions[size/2][size/2][2], size);
    center.x = new_center.x - center.x;
    center.y = center.y - new_center.y;
    for (int l = 0; l != size; l++)
        for (int m = 0; m != size; m++)
            for (int n = 0; n != 5; n++) {
                en->game.positions[l][m][n].x -= center.x;
                en->game.positions[l][m][n].y += center.y;
            }
}

void scale_up(engine_t *en, int size)
{
    sfVector2f center = get_middle(en->game.positions[size/2][size/2][0],
    en->game.positions[size/2][size/2][2], size);
    sfVector2f new_center;

    for (int i = 0; i != size; i++)
        for (int j = 0; j != size; j++)
            for (int k = 0; k != 5; k++) {
                en->game.positions[i][j][k].x *= 1.04f;
                en->game.positions[i][j][k].y *= 1.04f;
            }
    new_center = get_middle(en->game.positions[size/2][size/2][0],
    en->game.positions[size/2][size/2][2], size);
    center.x = new_center.x - center.x;
    center.y = center.y - new_center.y;
    for (int l = 0; l != size; l++)
        for (int m = 0; m != size; m++)
            for (int n = 0; n != 5; n++) {
                en->game.positions[l][m][n].x -= center.x;
                en->game.positions[l][m][n].y += center.y;
            }
}

void zoom_event_check(engine_t *en)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ) ||
    en->event.mouseWheelScroll.delta > 0) {
        if (en->game.scale <= 87.5f) {
            en->game.scale *= 1.04f;
            scale_up(en, en->game.map_size);
        }
    }
    if (sfKeyboard_isKeyPressed(sfKeyS) ||
    en->event.mouseWheelScroll.delta < 0) {
        if (en->game.scale >= (12 - (en->game.map_size / 25))) {
            en->game.scale *= (1/1.04f);
            scale_down(en, en->game.map_size);
        }
    }
}