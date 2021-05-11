/*
** EPITECH PROJECT, 2019
** STMNGR
** File description:
** General functions of the state manager
*/

#include "../../include/engine.h"

int stmngr_push(st_manager_t *manager, state_t *state, engine_t *engine)
{
    if (manager->top + 1 == manager->size)
        stmngr_scale(manager);
    manager->top++;
    manager->stack[manager->top] = state;
    if (state->init != NULL)
        state->init(engine);
    return (manager->top);
}

int stmngr_pop(st_manager_t *manager, engine_t *engine)
{
    state_t *top;

    if (manager->top == -1)
        return (0);
    top = stmngr_top(manager);
    if (top->destroy != NULL)
        top->destroy(engine);
    manager->stack[manager->top] = NULL;
    manager->top--;
    return (manager->top);
}

int stmngr_update(st_manager_t *manager, engine_t *engine)
{
    state_t *state = stmngr_top(manager);

    if (state->update != NULL)
        return (state->update(engine));
    return (1);
}

int stmngr_draw(st_manager_t *manager, engine_t *engine)
{
    state_t *state = stmngr_top(manager);

    if (state->draw != NULL)
        return (state->draw(engine));
    return (1);
}

int stmngr_event(st_manager_t *manager, engine_t *engine)
{
    state_t *state = stmngr_top(manager);

    if (state->event != NULL)
        return (state->event(engine));
    return (1);
}