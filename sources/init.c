/*
** EPITECH PROJECT, 2021
** palindrome
** File description:
** init
*/

#include "palindrome.h"

core_t *init_struct(void)
{
    core_t *data = malloc(sizeof(core_t));

    if (!data)
        exit(84);
    data->p = 0;
    data->n = 0;
    data->tmp = 0;
    data->min = 0;
    data->max = 100;
    data->b = 10;
    return data;
}