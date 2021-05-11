/*
** EPITECH PROJECT, 2020
** Scenes | Menu
** File description:
** Menu functions
*/

#include "../../include/engine.h"

unsigned int init_menu(engine_t *en)
{
    en = create_sprite(en, "srcs/assets/thumbnail_New map.jpg");
    en->graphics.view = sfView_create();
    my_printf("state 1 created\n");
    return (0);
}

unsigned int update_menu(void)
{
    return (0);
}

unsigned int event_menu(engine_t *en)
{
    if (en->event.type == sfEvtMouseButtonPressed) {
        if (en->graphics.menu.objects[0].position.x < en->mouse_pos_window.x \
        && en->mouse_pos_window.x <= en->graphics.menu.objects[0].position.x \
        + 410 && en->graphics.menu.objects[0].position.y < en-> \
        mouse_pos_window.y && en->mouse_pos_window.y <= \
        en->graphics.menu.objects[0].position.y + 120)
            stmngr_push(&en->manager, &en->graphics.game.state, en);
        if (check_leave(en) == 1)
            sfRenderWindow_close(en->graphics.window);
        en = check_helper(en);
        } if (en->event.type == sfEvtKeyPressed) {
            if (en->event.key.code == sfKeyG) {
                stmngr_push(&en->manager, &en->graphics.game.state, en);
            } if (en->event.key.code == sfKeyEscape) {
                sfRenderWindow_close(en->graphics.window);
    } } return (0);
}

unsigned int draw_menu(engine_t *en)
{
    sfRenderWindow_clear(en->graphics.window, sfColor_fromRGB(0, 40, 50));
    if (en->graphics.menu.objects[0].val == 1)
        sfRenderWindow_drawSprite(en->graphics.window,
    en->graphics.menu.objects[3].sprite, NULL);
    sfRenderWindow_drawSprite(en->graphics.window,
    en->graphics.menu.objects[0].sprite, NULL);
    sfRenderWindow_drawSprite(en->graphics.window,
    en->graphics.menu.objects[1].sprite, NULL);
    sfRenderWindow_drawSprite(en->graphics.window,
    en->graphics.menu.objects[2].sprite, NULL);
    sfRenderWindow_display(en->graphics.window);
    return (0);
}

unsigned int destroy_menu(engine_t *en)
{
    sfView_destroy(en->graphics.view);
    my_printf("state 1 destroyed\n");
    return (0);
}
