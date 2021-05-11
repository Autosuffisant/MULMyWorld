/*
** EPITECH PROJECT, 2020
** init game
** File description:
** Initialises all the variables needed for the game to run
*/

#include "../../include/engine.h"

void init_map(engine_t *en)
{
    en->game.map = set_map(en->game.map_size);
    en->game.colors = set_map(en->game.map_size);
    en->game.positions = set_map_coordinates(en, en->game.map_size,
    en->game.scale);
    en->game.vertex_tab = malloc(sizeof(sfVertexArray ***) * 2);
    en->game.vertex_tab[0] = set_vertex_sqr_tab(en, en->game.map_size,
    en->game.scale, 0);
    en->game.vertex_tab[1] = set_vertex_sqr_tab(en, en->game.map_size,
    en->game.scale, 1);
}