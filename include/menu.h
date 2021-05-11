/*
** EPITECH PROJECT, 2020
** State
** File description:
** Functions of Menu state
*/

#ifndef H_MENU
#define H_MENU

#include "engine.h"

unsigned int init_menu(engine_t *engine);
unsigned int update_menu(engine_t *engine);
unsigned int event_menu(engine_t *engine);
unsigned int draw_menu(engine_t *engine);
unsigned int destroy_menu(engine_t *engine);

#endif