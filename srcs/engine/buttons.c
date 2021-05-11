/*
** EPITECH PROJECT, 2019
** My World | Buttons
** File description:
** Generic button functions
*/

#include "../../include/engine.h"

void init_button(button_t *button, sfVector2f pos,
                sfVector2f size, sfTexture *texture)
{
    button->rect = sfRectangleShape_create();
    sfRectangleShape_setTexture(button->rect, texture, sfFalse);
    sfRectangleShape_setPosition(button->rect, pos);
    sfRectangleShape_setSize(button->rect, size);
    sfRectangleShape_setFillColor(button->rect, sfColor_fromRGB(240, 240, 255));
}

void which_button_is_clicked(engine_t *en, int a)
{
    if (a == 0)
        en->game.build_mode = 1;
    if (a == 1)
        en->game.build_mode = 0;
    if (a == 2)
        scale_down(en, en->game.map_size);
    if (a == 3)
        scale_up(en, en->game.map_size);
    if (a == 4)
        save_init(en, en->game.map_size);
    if (a == 5)
        heights_reset(en);
    if (a == 6)
        stmngr_pop(&en->manager, en);
}

void highlight_buttons(engine_t *en)
{
    for (int i = 0; i != 7; i++)
        if (is_clicked(&en->graphics.game.buttons[i],
        en->mouse_pos_window) == 1) {
            sfRectangleShape_setFillColor(en->graphics.game.buttons[i].rect,
            sfColor_fromRGB(150, 150, 170));
        } else {
            sfRectangleShape_setFillColor(en->graphics.game.buttons[i].rect,
            sfColor_fromRGB(240, 240, 255));
        }
    if ((en->game.build_mode % 2) == 0) {
        sfRectangleShape_setFillColor(en->graphics.game.buttons[1].rect,
        sfColor_fromRGB(180, 180, 255));
    } else {
        sfRectangleShape_setFillColor(en->graphics.game.buttons[0].rect,
        sfColor_fromRGB(180, 180, 255));
    }
}

int is_clicked(button_t *button, sfVector2i click_pos)
{
    sfVector2f pos = sfRectangleShape_getPosition(button->rect);
    sfVector2f size = sfRectangleShape_getSize(button->rect);
    sfIntRect tmp;

    tmp.top = pos.y;
    tmp.left = pos.x;
    tmp.height = size.y;
    tmp.width = size.x;
    if (sfIntRect_contains(&tmp, click_pos.x, click_pos.y)) {
        return (1);
    } else
        return (0);
}

void destroy_button(button_t *button)
{
    sfRectangleShape_destroy(button->rect);
}