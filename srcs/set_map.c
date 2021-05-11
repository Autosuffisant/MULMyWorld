/*
** EPITECH PROJECT, 2020
** my_world map
** File description:
** map setup functions
*/

#include "../include/engine.h"

sfVertexArray *set_sqr(sfVertex point, int gap, int prop)
{
    sfVertexArray *square = sfVertexArray_create();

    sfVertexArray_setPrimitiveType(square, sfQuads);
    if (prop == 1)
        sfVertexArray_setPrimitiveType(square, sfLinesStrip);
    sfVertexArray_append(square, point);
    point.position.x += gap;
    sfVertexArray_append(square, point);
    point.position.y += gap;
    sfVertexArray_append(square, point);
    point.position.x -= gap;
    sfVertexArray_append(square, point);
    point.position.y -= gap;
    sfVertexArray_append(square, point);
    return (square);
}

sfVertexArray ***set_vertex_sqr_tab(engine_t *en, int size, float gap, int prop)
{
    sfVector2f win_size = sfView_getCenter(en->graphics.view);
    sfVertexArray ***vertex_tab = malloc(sizeof(sfVertexArray **) * size);
    sfVertex point;

    point.color = sfColor_fromRGB(186, 218, 85);
    point.position.x = win_size.x - gap;
    point.position.y = win_size.y - gap;
    for (int j = 0; j != size; j++, point.position.y += gap) {
        vertex_tab[j] = malloc(sizeof(sfVertexArray *) * size);
        point.position.x = win_size.x - gap;
        for (int i = 0; i != size; i++, point.position.x += gap)
            vertex_tab[j][i] = set_sqr(point, gap, prop);
    }
    return (vertex_tab);
}

int ***set_map(int size)
{
    int ***map = malloc(sizeof(int **) * size);

    for (int h = 0; h < size; h++) {
        map[h] = malloc(sizeof(int *) * size);
        for (int i = 0; i < size; i++) {
            map[h][i] = malloc(sizeof(int) * 5);
            for (int j = 0; j < 5; j++)
                map[h][i][j] = 0;
            }
        }
    return (map);
}

sfVector2f *set_coordinates_tab(sfVector2f pos, int gap)
{
    sfVector2f *pos_tab = malloc(sizeof(sfVector2f) * 5 + 1);

    pos_tab[0] = pos;
    pos.x += gap;
    pos_tab[1] = pos;
    pos.y += gap;
    pos_tab[2] = pos;
    pos.x -= gap;
    pos_tab[3] = pos;
    pos.y -= gap;
    pos_tab[4] = pos;
    return (pos_tab);
}

sfVector2f ***set_map_coordinates(engine_t *en, int size, float gap)
{
    sfVector2f ***pos_tab = malloc(sizeof(sfVector2f **) * size);
    sfVector2u win_size = sfRenderWindow_getSize(en->graphics.window);
    sfVector2f pos;

    pos.y = win_size.y / 2 - gap;
    for (int h = 0; h != size; h++, pos.y += gap) {
        pos_tab[h] = malloc(sizeof(sfVector2f *) * size);
        pos.x = win_size.x / 2 - gap;
        for (int i = 0; i != size; i++, pos.x += gap)
            pos_tab[h][i] = set_coordinates_tab(pos, gap);
    }
    return (pos_tab);
}