/*
** EPITECH PROJECT, 2019
** Template
** File description:
** Main
*/

#include "../include/engine.h"

int main_game_loop(engine_t en)
{
    if (engine_init(&en) == -1) {
        engine_free(&en);
        return (84);
    }
    init_states(&en);
    stmngr_push(&en.manager, &en.graphics.menu.state, &en);
    while (sfRenderWindow_isOpen(en.graphics.window)) {
        get_mouse_pos(&en);
        en.dt = sfClock_restart(en.clock);
        en.deltatime = sfTime_asSeconds(en.dt);
        while (sfRenderWindow_pollEvent(en.graphics.window, &en.event)) {
            if (en.event.type == sfEvtClosed)
                sfRenderWindow_close(en.graphics.window);
            stmngr_event(&en.manager, &en);
        } stmngr_update(&en.manager, &en);
        stmngr_draw(&en.manager, &en);
    } engine_free(&en);
    return (0);
}

void helper(void)
{
    my_putstr("\nMy_world is a simple map editor made by Gabriel");
    my_putstr(" Huguenin-Dumittan, Aurelien Schulz and Loan Galluzo\n\n");
    my_putstr("The program allows you to create a map and edit it\n");
    my_putstr("The default size is 9, to change it you have to change the");
    my_putstr(" code\n\nThis world editor allows you to perform the following");
    my_putstr(" actions :\n\nAverage a map's height - first button\n");
    my_putstr("Lower or rise a map's height - second button\n");
    my_putstr("Zoom and dezoom - third and fourth buttons or the mousewheel\n");
    my_putstr("Save the map in a file (you cannot import it) - fifth button");
    my_putstr(" or the LCTRL key\nThe map is in the /save directory\n");
    my_putstr("Reset all the map's heights - sixth button\n");
    my_putstr("Return to the menu - last button or ESC key\n\n");
    my_putstr("You can move the map using the arrow keys, center it by ");
    my_putstr("pressing the C key and reset with the R key\n");
}

int main(int argc, char **argv)
{
    engine_t engine = { 0 };

    if (argc == 2) {
        if (my_strcmp(argv[1], "-h") == 0) {
            helper();
            return (0);
        } else {
            return (main_game_loop(engine));
        }
    } else {
        return (main_game_loop(engine));
    }
    return (0);
}