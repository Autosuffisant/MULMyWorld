/*
** EPITECH PROJECT, 2019
** My World | UI
** File description:
** UI Functions
*/

#include "../../include/engine.h"

sfTexture **set_buttons_textures(void)
{
    sfTexture **texture = malloc(sizeof(sfTexture *) * 11);

    texture[0] = sfTexture_createFromFile("./srcs/assets/medium.png", NULL);
    texture[1] = sfTexture_createFromFile("./srcs/assets/height.png", NULL);
    texture[2] = sfTexture_createFromFile("./srcs/assets/zoom-.png", NULL);
    texture[3] = sfTexture_createFromFile("./srcs/assets/zoom+.png", NULL);
    texture[4] = sfTexture_createFromFile("./srcs/assets/save2.png", NULL);
    texture[5] = sfTexture_createFromFile("./srcs/assets/reset.png", NULL);
    texture[6] = sfTexture_createFromFile("./srcs/assets/exicon.png", NULL);
    return (texture);
}

void init_ui(engine_t *en)
{
    en->graphics.game.buttons = malloc(sizeof(button_t) * 7);
    sfTexture **texture = set_buttons_textures();
    sfVector2f scale = { 120, 120};
    sfVector2f pos = { 20, 15 };

    for (int i = 0; i < 7; i++, pos.x += 150) {
        if (i == 2) {
            pos.x += 400;
        } else if (i == 4) {
            pos.x += 300;
        }
        pos.x += 20;
        init_button(&en->graphics.game.buttons[i], pos, scale, texture[i]);
    }
}

void draw_ui(engine_t *en)
{
    for (int i = 0; i < 7; i++) {
        sfRenderWindow_drawRectangleShape(en->graphics.window,
        en->graphics.game.buttons[i].rect, NULL);
    }
}

void destroy_ui(engine_t *en)
{
    for (int i = 0; i < 7; i++) {
        destroy_button(&en->graphics.game.buttons[i]);
    }
    free(en->graphics.game.buttons);
}