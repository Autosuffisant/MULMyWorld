/*
** EPITECH PROJECT, 2010
** Engine
** File description:
** Engine generic functions
*/

#include "../../include/engine.h"

int engine_init(engine_t *engine)
{
    engine->clock = sfClock_create();
    if (graphics_init(&engine->graphics) != 0) {
        return (84);
    }
    stmngr_init(&engine->manager);
    return (0);
}

int winvar_init(window_t *winvars)
{
    winvars->framerate = 60;
    winvars->width = 1920;
    winvars->height = 1080;
    winvars->title = "MyWorld";
    return (0);
}

int graphics_init(graphics_t *graphics)
{
    winvar_init(&graphics->winvar);
    sfVideoMode mode = { graphics->winvar.width, graphics->winvar.height, 32 };

    graphics->window = sfRenderWindow_create(mode, graphics->winvar.title, \
                                            sfClose, NULL);
    if (!graphics->window)
        return (84);
    sfRenderWindow_setFramerateLimit(graphics->window, \
                                    graphics->winvar.framerate);
    sfRenderWindow_setKeyRepeatEnabled(graphics->window, sfFalse);
    return (0);
}

int engine_free(engine_t *engine)
{
    stmngr_free(&engine->manager, engine);
    graphics_free(&engine->graphics);
    sfClock_destroy(engine->clock);
    return (0);
}

int graphics_free(graphics_t *graphics)
{
    sfRenderWindow_destroy(graphics->window);
    return (0);
}