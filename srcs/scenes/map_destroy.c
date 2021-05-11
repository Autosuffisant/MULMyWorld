/*
** EPITECH PROJECT, 2020
** world map destroy
** File description:
** functions linked to the map's destruction
*/

#include "../../include/engine.h"

void vertex_array_destroy(engine_t *en)
{
    for (int l = 0; l != 2; l++) {
        for (int k = 0; k != en->game.map_size; k++) {
            for (int j = 0; j != en->game.map_size; j++) {
                sfVertexArray_clear(en->game.vertex_tab[l][k][j]);
                sfVertexArray_destroy(en->game.vertex_tab[l][k][j]);
            }
            free(en->game.vertex_tab[l][k]);
        }
        free(en->game.vertex_tab[l]);
    }
    free(en->game.vertex_tab);
}

void map_properties_destroy(engine_t *en)
{
    for (int h = 0; h != en->game.map_size; h++) {
        for (int i = 0; i != en->game.map_size; i++) {
            free(en->game.colors[h][i]);
            free(en->game.map[h][i]);
        }
        free(en->game.colors[h]);
        free(en->game.map[h]);
    }
    free(en->game.colors);
    free(en->game.map);
}

void map_vectors_destroy(engine_t *en)
{
    for (int a = 0; a != en->game.map_size; a++) {
        for (int b = 0; b != en->game.map_size; b++)
                free(en->game.positions[a][b]);
            free(en->game.positions[a]);
        }
    free(en->game.positions);
}

void map_destroy(engine_t *en)
{
    vertex_array_destroy(en);
    map_properties_destroy(en);
    map_vectors_destroy(en);
}