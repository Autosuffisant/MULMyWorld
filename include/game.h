/*
** EPITECH PROJECT, 2020
** State
** File description:
** Functions of Menu state
*/

#ifndef H_GAME
#define H_GAME

#include "engine.h"

unsigned int init_game(engine_t *engine);
unsigned int update_game(engine_t *engine);
unsigned int event_game(engine_t *engine);
unsigned int draw_game(engine_t *engine);
unsigned int destroy_game(engine_t *engine);

#endif