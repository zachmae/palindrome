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

static void do_end(int nb, char *str, int base, int c)
{
    my_printf("%d leads to %d in %d iteration(s) in base %d\n",
        nb, base_to_decim(str, base), c, base);
    exit(0);
}

void do_npalindrome(core_t *core)
{
    char *save = base_converter(core->n, core->b);
    char *new = my_revstr(my_strdup(save));
    int revnb;

    for (int c = 0; c <= core->max; ++c) {
        if (my_strcmp(save, new) == 0 && c >= core->min)
            do_end(core->n, new, core->b, c);
        revnb = base_to_decim(new, core->b) + base_to_decim(save, core->b);
        free(save);
        free(new);
        new = base_converter(revnb, core->b);
        save = my_revstr(my_strdup(new));
        new = my_revstr(my_strdup(save));
    }
    free(save);
    free(new);
    my_printf("no solution\n");
}