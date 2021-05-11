/*
** EPITECH PROJECT, 2020
** Engine
** File description:
** Gets the mouse position in the screen and the window
*/

#include "../../include/engine.h"

int get_mouse_pos(engine_t *engine)
{
    engine->mouse_pos_screen = sfMouse_getPosition(NULL);
    engine->mouse_pos_window = \
    sfMouse_getPositionRenderWindow(engine->graphics.window);
    engine->mouse_pos_view = sfRenderWindow_mapPixelToCoords(
    engine->graphics.window, engine->mouse_pos_window,
    engine->graphics.view);
    return (0);
}