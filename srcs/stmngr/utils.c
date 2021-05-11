/*
** EPITECH PROJECT, 2020
** STMNGR
** File description:
** Utility functions for the State Manager
*/

#include "../../include/engine.h"

state_t *stmngr_top(st_manager_t *manager)
{
    return (manager->stack[manager->top]);
}

int stmngr_scale(st_manager_t *manager)
{
    manager->size *= 2;
    manager->stack = my_realloc(manager->stack, (manager->size / 2) * \
                                sizeof(state_t *), manager->size * \
                                sizeof(state_t *));
    return manager->size;
}