/*
** EPITECH PROJECT, 2020
** my world include
** File description:
** include
*/

#ifndef WORLD_
#define WORLD_

#include <SFML/Graphics.h>
#include <math.h>
#include <stdio.h>

typedef struct game_s {
    int map_size;
    int angle;
    int ***map;
    int ***colors;
    float scale;
    int build_mode;
    sfVector2f ***positions;
    sfVertexArray ****vertex_tab;
} game_t;

#endif /* !WORLD_ */
