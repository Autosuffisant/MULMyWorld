/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** engine.h
*/

#ifndef H_ENGINE
#define H_ENGINE

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <unistd.h>
#include "../include/my.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "world.h"

struct engine_s;

typedef unsigned int (*fptr_f)(struct engine_s *);

typedef struct state_s {
    fptr_f init;
    fptr_f update;
    fptr_f draw;
    fptr_f event;
    fptr_f destroy;
} state_t;

typedef struct st_manager_s {
    state_t **stack;
    int size;
    int top;
} st_manager_t;

typedef struct button_s {
    sfRectangleShape *rect;
    void (*fptr)();
} button_t;

typedef struct game_objects_s {
    sfVector2f position;
    sfIntRect rect;
    sfTexture *texture;
    sfSprite *sprite;
    int val;
} game_objects_t;

typedef struct window_s {
    char *title;
    int width;
    int height;
    int framerate;
} window_t;

typedef struct scene_s {
    game_objects_t *objects;
    button_t *buttons;
    state_t state;
} scene_t;

typedef struct graphics_s {
    sfRenderWindow *window;
    window_t winvar;
    float view_speed;
    sfView *view;
    scene_t menu;
    scene_t game;
} graphics_t;

typedef struct engine_s {
    graphics_t graphics;
    st_manager_t manager;
    game_t game;
    sfEvent event;
    sfClock *clock;
    sfTime dt;
    sfVector2i mouse_pos_screen;
    sfVector2i mouse_pos_window;
    sfVector2f mouse_pos_view;
    float deltatime;
} engine_t;

int engine_init(engine_t *engine);
int engine_free(engine_t *engine);

int graphics_init(graphics_t *graphics);
int graphics_free(graphics_t *graphics);

int stmngr_init(st_manager_t *manager);
int stmngr_free(st_manager_t *manager, engine_t *engine);
int stmngr_push(st_manager_t *manager, state_t *state, engine_t *engine);
int stmngr_pop(st_manager_t *manager, engine_t *engine);
int stmngr_update(st_manager_t *manager, engine_t *engine);
int stmngr_event(st_manager_t *manager, engine_t *engine);
int stmngr_draw(st_manager_t *manager, engine_t  *engine);
int stmngr_scale(st_manager_t *manager);
state_t *stmngr_top(st_manager_t *manager);


void init_map(engine_t *en);
int ***set_map(int size);
int get_mouse_pos(engine_t *engine);
void update_map_coordinates(engine_t *en);
sfVertexArray ***set_vertex_sqr_tab(engine_t *en, int size, float gap, int typ);
sfVector2f ***set_map_coordinates(engine_t *en, int size, float gap);
sfVector2f  project_iso_point(  sfVector2f pos, int height);
int set_map_to_3d(engine_t *en, int size);
int map_center(engine_t *en, int size);
int camera_center(engine_t *en, int size);
void mouse_input(engine_t *en);
void check_move_inputs(engine_t *en);
int increase_y_map_coordinates(engine_t *en, int size, int scale);
int decrease_y_map_coordinates(engine_t *en, int size, int scale);
int increase_x_map_coordinates(engine_t *en, int size, int scale);
int decrease_x_map_coordinates(engine_t *en, int size, int scale);
void zoom_event_check(engine_t *en);
void scale_up(engine_t *en, int size);
void scale_down(engine_t *en, int size);
int raise_vertex_check(engine_t *en, int size);
int lower_vertex_check(engine_t *en, int size);
void height_average_check(engine_t *en);
int heights_reset(engine_t *en);
void init_states(engine_t *engine);
engine_t *create_sprite(engine_t *en, const char *src);
unsigned int init_leaving_button(engine_t *en);
unsigned int leaving_button(engine_t *en);
engine_t *create_sprite_quit(engine_t *en, const char *src);
int check_leave(engine_t *en);
int save_init(engine_t *en, int size);
engine_t *create_sprite_helper(engine_t *en, const char *src);
engine_t *check_helper(engine_t *en);
unsigned int help_function(engine_t *en);
void init_button(button_t *button, sfVector2f pos,
sfVector2f size, sfTexture *texture);
void init_ui(engine_t *en);
void draw_ui(engine_t *en);
int is_clicked(button_t *button, sfVector2i click_pos);
void which_button_is_clicked(engine_t *en, int a);
void highlight_buttons(engine_t *en);
void destroy_button(button_t *button);
void map_destroy(engine_t *en);
void destroy_ui(engine_t *en);
engine_t *create_box(engine_t *en, const char *src);

#endif