/*
** EPITECH PROJECT, 2020
** my put rev
** File description:
** put reverse string
*/

#include "my.h"

void my_putrev(char *str)
{
    for (int c = my_strlen(str) ; c != -1; c--)
        my_putchar(str[c]);
    return;
}
