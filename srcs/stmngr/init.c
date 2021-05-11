/*
** EPITECH PROJECT, 2020
** STMNGR
** File description:
** Initialize the state manager
*/

#include "../../include/engine.h"

int stmngr_init(st_manager_t *manager)
{
    manager->size = 128;
    manager->stack = malloc(manager->size * sizeof(state_t *));
    manager->top = -1;
    return (0);
}