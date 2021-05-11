/*
** EPITECH PROJECT, 2020
** map move
** File description:
** Functions which allow the map to be moved
*/

#include "../include/engine.h"

int increase_y_map_coordinates(engine_t *en, int size, int scale)
{
    int move_factor = 25;

    if (scale < 20)
        move_factor *= 1/1.5f;
    for (int i = 0; i != size; i++)
        for (int j = 0; j != size; j++)
            for (int k = 0; k != 5; k++) {
                en->game.positions[i][j][k].y -=
                move_factor / (scale * 0.1f);
            }
    return (0);
}

int decrease_y_map_coordinates(engine_t *en, int size, int scale)
{
    int move_factor = 25;

    if (scale < 20)
        move_factor *= 1/1.5f;
    for (int i = 0; i != size; i++)
        for (int j = 0; j != size; j++)
            for (int k = 0; k != 5; k++) {
                en->game.positions[i][j][k].y +=
                move_factor / (scale * 0.1f);
            }
    return (0);
}

int increase_x_map_coordinates(engine_t *en, int size, int scale)
{
    int move_factor = 25;

    if (scale < 20)
        move_factor *= 1/1.5f;
    for (int i = 0; i != size; i++)
        for (int j = 0; j != size; j++)
            for (int k = 0; k != 5; k++) {
                en->game.positions[i][j][k].x +=
                move_factor / (scale * 0.1f);
            }
    return (0);
}

int decrease_x_map_coordinates(engine_t *en, int size, int scale)
{
    int move_factor = 25;

    if (scale < 20)
        move_factor *= 1/1.5f;
    for (int i = 0; i != size; i++)
        for (int j = 0; j != size; j++)
            for (int k = 0; k != 5; k++) {
                en->game.positions[i][j][k].x -=
                move_factor / (scale * 0.1f);
            }
    return (0);
}

void check_move_inputs(engine_t *en)
{
    if (sfKeyboard_isKeyPressed(sfKeyRight))
        decrease_x_map_coordinates(en, en->game.map_size, en->game.scale);
    if (sfKeyboard_isKeyPressed(sfKeyLeft))
        increase_x_map_coordinates(en, en->game.map_size, en->game.scale);
    if (sfKeyboard_isKeyPressed(sfKeyDown))
        increase_y_map_coordinates(en, en->game.map_size, en->game.scale);
    if (sfKeyboard_isKeyPressed(sfKeyUp))
        decrease_y_map_coordinates(en, en->game.map_size, en->game.scale);
}