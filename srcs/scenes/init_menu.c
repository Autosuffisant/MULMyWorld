/*
** EPITECH PROJECT, 2020
** init_menu
** File description:
** my_world
*/

#include "../../include/engine.h"

game_objects_t *malloc_game_objects(game_objects_t *object, int i)
{
    object = malloc(sizeof(game_objects_t) * i);
    return (object);
}

void free_game_object(game_objects_t *object)
{
    free(object);
}

engine_t *create_sprite(engine_t *en, const char *src)
{
    game_objects_t button_sprite = { 0 };

    button_sprite.rect.height = 120;
    button_sprite.rect.width = 410;
    button_sprite.rect.top = 0;
    button_sprite.rect.left = 0;
    button_sprite.sprite = sfSprite_create();
    button_sprite.texture = sfTexture_createFromFile(src, NULL);
    sfSprite_setTexture(button_sprite.sprite, button_sprite.texture, sfTrue);
    sfSprite_setTextureRect(button_sprite.sprite, button_sprite.rect);
    en->graphics.menu.objects = malloc(sizeof(button_sprite)* 4);
    en->graphics.menu.objects[0] = button_sprite;
    en->graphics.menu.objects[0].position.x = 700;
    en->graphics.menu.objects[0].position.y = 200;
    en->graphics.menu.objects[0].val = 0;
    sfSprite_setPosition(en->graphics.menu.objects[0].sprite,
    en->graphics.menu.objects[0].position);
    en = create_sprite_quit(en, "srcs/assets/thumbnail_exit_menu.png");
    return (en);
}

engine_t *create_sprite_quit(engine_t *en, const char *src)
{
    game_objects_t button_sprite = { 0 };

    button_sprite.rect.height = 120;
    button_sprite.rect.width = 410;
    button_sprite.rect.top = 0;
    button_sprite.rect.left = 0;
    button_sprite.sprite = sfSprite_create();
    button_sprite.texture = sfTexture_createFromFile(src, NULL);
    sfSprite_setTexture(button_sprite.sprite, button_sprite.texture, sfTrue);
    sfSprite_setTextureRect(button_sprite.sprite, button_sprite.rect);
    en->graphics.menu.objects[1] = button_sprite;
    en->graphics.menu.objects[1].position.x = 700;
    en->graphics.menu.objects[1].position.y = 800;
    sfSprite_setPosition(en->graphics.menu.objects[1].sprite,
    en->graphics.menu.objects[1].position);
    en = create_sprite_helper(en, "srcs/assets/thumbnail_Help.png");
    return (en);
}

engine_t *create_sprite_helper(engine_t *en, const char *src)
{
    game_objects_t button_sprite = { 0 };

    button_sprite.rect.height = 120;
    button_sprite.rect.width = 410;
    button_sprite.rect.top = 0;
    button_sprite.rect.left = 0;
    button_sprite.sprite = sfSprite_create();
    button_sprite.texture = sfTexture_createFromFile(src, NULL);
    sfSprite_setTexture(button_sprite.sprite, button_sprite.texture, sfTrue);
    sfSprite_setTextureRect(button_sprite.sprite, button_sprite.rect);
    en->graphics.menu.objects[2] = button_sprite;
    en->graphics.menu.objects[2].position.x = 700;
    en->graphics.menu.objects[2].position.y = 500;
    sfSprite_setPosition(en->graphics.menu.objects[2].sprite,
    en->graphics.menu.objects[2].position);
    en = create_box(en, "srcs/assets/text_box.png");
    return (en);
}
