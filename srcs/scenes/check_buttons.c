/*
** EPITECH PROJECT, 2020
** in game buttons gestion
** File description:
** my_wolrd
*/

#include "../../include/engine.h"

int check_leave(engine_t *en)
{
    if (en->event.type == sfEvtMouseButtonPressed) {
        if (en->graphics.menu.objects[1].position.x < en->mouse_pos_window.x \
        && en->mouse_pos_window.x <= en->graphics.menu.objects[1].position.x \
        + 410 && en->graphics.menu.objects[1].position.y < en-> \
        mouse_pos_window.y && en->mouse_pos_window.y <=
        en->graphics.menu.objects[1].position.y + 120)
            return (1);
    }
    return (0);
}

engine_t *check_helper(engine_t *en)
{
    return (en);
}

engine_t *create_box(engine_t *en, const char *src)
{
    game_objects_t button_sprite = { 0 };

    button_sprite.rect.height = 152;
    button_sprite.rect.width = 578;
    button_sprite.rect.top = 0;
    button_sprite.rect.left = 0;
    button_sprite.sprite = sfSprite_create();
    button_sprite.texture = sfTexture_createFromFile(src, NULL);
    sfSprite_setTexture(button_sprite.sprite, button_sprite.texture, sfTrue);
    sfSprite_setTextureRect(button_sprite.sprite, button_sprite.rect);
    en->graphics.menu.objects[3] = button_sprite;
    en->graphics.menu.objects[3].position.x = 1300;
    en->graphics.menu.objects[3].position.y = 500;
    en->graphics.menu.objects[3].val = 0;
    sfSprite_setPosition(en->graphics.menu.objects[3].sprite,
    en->graphics.menu.objects[3].position);
    return (en);
}