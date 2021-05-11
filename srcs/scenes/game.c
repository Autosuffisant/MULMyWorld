/*
** EPITECH PROJECT, 2020
** Scenes | Menu
** File description:
** Menu functions
*/

#include "../../include/engine.h"

unsigned int init_game(engine_t *en)
{
    en->game.map_size = 10;
    en->game.scale = 50;
    en->game.build_mode = 0;
    init_map(en);
    init_ui(en);
    set_map_to_3d(en, en->game.map_size);
    map_center(en, en->game.map_size);
    camera_center(en, en->game.map_size);
    my_printf("state 2 created\n");
    return (0);
}

unsigned int update_game(engine_t *en)
{
    check_move_inputs(en);
    highlight_buttons(en);
    if (sfKeyboard_isKeyPressed(sfKeyA))
        height_average_check(en);
    if (sfKeyboard_isKeyPressed(sfKeyR))
        heights_reset(en);
    if (sfKeyboard_isKeyPressed(sfKeyLControl))
        save_init(en, en->game.map_size);
    mouse_input(en);
    update_map_coordinates(en);
    if (en->deltatime > 1) {
        my_printf("1 second has passed...\n");
    }
    return (0);
}

unsigned int event_game(engine_t *en)
{
    if (en->event.type == sfEvtKeyPressed) {
        if (en->event.key.code == sfKeyEscape)
            stmngr_pop(&en->manager, en);
        if (sfKeyboard_isKeyPressed(sfKeyC)) {
            map_center(en, en->game.map_size);
            camera_center(en, en->game.map_size);
        }
    }
    if (en->event.type == sfEvtMouseButtonPressed)
        for (int i = 0; i != 7; i++)
            if (is_clicked(&en->graphics.game.buttons[i],
            en->mouse_pos_window) == 1)
                which_button_is_clicked(en, i);
    if (en->event.type == sfEvtMouseWheelScrolled)
        zoom_event_check(en);
    return (0);
}

unsigned int draw_game(engine_t *en)
{
    sfRectangleShape *shape = sfRectangleShape_create();
    sfRectangleShape_setPosition(shape, (sfVector2f) { 0.f, 0.f });
    sfRectangleShape_setSize(shape, (sfVector2f) { 1920, 150 });
    sfRectangleShape_setFillColor(shape, sfColor_fromRGB(0, 40, 50));
    sfRenderWindow_clear(en->graphics.window, sfColor_fromRGB(0, 75, 80));
    for (int a = 0; a != 2; a++)
        for (int i = 0; i != en->game.map_size; i++)
            for (int j = 0; j != en->game.map_size; j++)
                sfRenderWindow_drawVertexArray(en->graphics.window,
                                            en->game.vertex_tab[a][i][j], NULL);
    sfRenderWindow_drawRectangleShape(en->graphics.window, shape, NULL);
    draw_ui(en);
    sfRenderWindow_display(en->graphics.window);
    sfRectangleShape_destroy(shape);
    return (0);
}

unsigned int destroy_game(engine_t *en)
{
    map_destroy(en);
    destroy_ui(en);
    my_printf("state 2 destroyed\n");
    return (0);
}