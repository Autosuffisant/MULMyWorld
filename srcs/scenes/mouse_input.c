/*
** EPITECH PROJECT, 2020
** my_world mouse_input
** File description:
** Function which checks what has to be done when a mouse input happens
*/

#include "../../include/engine.h"

void mouse_input(engine_t *en)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (en->game.build_mode == 0)
            raise_vertex_check(en, en->game.map_size);
        if (en->game.build_mode == 1)
            height_average_check(en);
    }
    if (sfMouse_isButtonPressed(sfMouseRight)) {
        if (en->game.build_mode == 0)
            lower_vertex_check(en, en->game.map_size);
        if (en->game.build_mode == 1)
            height_average_check(en);
    }
}