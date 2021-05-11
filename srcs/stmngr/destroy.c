/*
** EPITECH PROJECT, 2020
** STMNGR
** File description:
** Destroy the whole state pile and then itself
*/

#include "../../include/engine.h"

int stmngr_free(st_manager_t *manager, engine_t *engine)
{
    while (manager->top > -1)
        stmngr_pop(manager, engine);
    free(manager->stack);
    return (0);
}