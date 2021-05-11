/*
** EPITECH PROJECT, 2020
** STMNGR
** File description:
** Init functions pointers of scenes
*/

#include "../../include/engine.h"
#include "../../include/menu.h"
#include "../../include/game.h"

static void menu_state_init(engine_t *en)
{
    en->graphics.menu.state.init = init_menu;
    en->graphics.menu.state.update = update_menu;
    en->graphics.menu.state.event = event_menu;
    en->graphics.menu.state.draw = draw_menu;
    en->graphics.menu.state.destroy = destroy_menu;
}

static void game_state_init(engine_t *en)
{
    en->graphics.game.state.init = init_game;
    en->graphics.game.state.update = update_game;
    en->graphics.game.state.event = event_game;
    en->graphics.game.state.draw = draw_game;
    en->graphics.game.state.destroy = destroy_game;
}

void init_states(engine_t *engine)
{
    menu_state_init(engine);
    game_state_init(engine);
}
