/*
** EPITECH PROJECT, 2020
** my isneg
** File description:
** contain the function my isneg
*/

#include "my.h"

int my_isneg(int nb)
{
    return (my_putstr(nb >= 0 ? "P\n" : "N\n"));
}
