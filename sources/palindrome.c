/*
** EPITECH PROJECT, 2021
** palindrome
** File description:
** palindrome
*/

#include "palindrome.h"

int palindrome(int ac, char **av)
{
    core_t *core = init_struct();

    parse_flag(ac, av, core);
    if (core->nflag == 1)
        do_npalindrome(core);
    else
        do_ppalindrome(core);
    free(core);
    return 0;
}