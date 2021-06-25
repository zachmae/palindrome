/*
** EPITECH PROJECT, 2021
** palindrome
** File description:
** palindrome
*/

#include "palindrome.h"
#include "const.h"

void parse_flag(int ac, char **av, core_t *core)
{
    for (int c = 1; c < ac; c += 2) {
        if (my_strcmp(av[c], nflag) == 0) {
            core->n = my_getnbr(av[c + 1]);
            core->nflag++;
        } if (my_strcmp(av[c], pflag) == 0) {
            core->p = my_getnbr(av[c + 1]);
            core->pflag++;
        } if (my_strcmp(av[c], bflag) == 0)
            core->b = my_getnbr(av[c + 1]);
        if (my_strcmp(av[c], min) == 0)
            core->min = my_getnbr(av[c + 1]);
        if (my_strcmp(av[c], max) == 0)
            core->max = my_getnbr(av[c + 1]);
        if (my_strcmp(av[c], nflag) && my_strcmp(av[c], pflag) &&
            my_strcmp(av[c], bflag) && my_strcmp(av[c], min) &&
            my_strcmp(av[c], max))
            do_invalid();
    }
    if (core->nflag + core->pflag != 1 || core->n < 0 || core->p < 0 ||
        core->b < 2 || core->b > 10 || core->min < 0 || core->min > core->max)
        do_invalid();
}