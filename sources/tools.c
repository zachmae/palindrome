/*
** EPITECH PROJECT, 2021
** palindrome
** File description:
** tools
*/

#include <stdbool.h>
#include "palindrome.h"
#include "const.h"
#include "my.h"

char *base_converter(int nb, int base)
{
    int loop;
    char numbers[11] = "0123456789";
    char *str = malloc(sizeof(char *) * 32);

    if (str == NULL)
        exit(84);
    for (loop = 0; loop < 31 && nb != 0; ++loop) {
        str[loop] = numbers[nb % base];
        nb /= base;
    }
    str[loop] = '\0';
    return my_revstr(str);
}

static int char_to_int(char c)
{
    return (c >= 48 && c <= 57 ? c - 48 : c - 55);
}

int base_to_decim(char *str, int base)
{
    int mult = 1;
    int nb = 0;

    if (base == 10)
        return (my_getnbr(str));
    for (int len = my_strlen(str) - 1; len >= 0; len--) {
        nb += char_to_int(str[len]) * mult;
        mult *= base;
    }
    return nb;
}

bool check_palindrome(int nb, int base)
{
    return (my_strcmp(base_converter(nb, base),
        my_revstr(base_converter(nb, base)))
        == 0 ? true: false);
}