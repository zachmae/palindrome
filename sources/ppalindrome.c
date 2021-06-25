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

static void put_step(int value, int cpt, core_t *core)
{
    my_printf("%d leads to %d in %d iteration(s) in base %d\n",
        value, core->p, cpt, core->b);
    core->tmp++;
}

static void make_algo(core_t *core, int value)
{
    char *new = malloc(sizeof(char) * 32);
    char *save = malloc(sizeof(char) * 32);
    int sum;

    save = base_converter(value, core->b);
    new = base_converter(core->p, core->b);
    for (int c = 0; c <= core->max; ++c) {
        if (my_strcmp(my_revstr(save), new) == 0 && c >= core->min) {
            put_step(value, c, core);
            return;
        }
        sum = base_to_decim(save, core->b) +
            base_to_decim(my_revstr(save), core->b);
        free(save);
        save = base_converter(sum, core->b);
    }
    free(save);
    free(new);
}

void do_ppalindrome(core_t *core)
{
    if (check_palindrome(core->p, core->b) == false)
        do_invalid();
    for (int c = 1; c <= core->p; ++c)
        make_algo(core, c);
    if (core->tmp <= 0)
        my_printf("no solution\n");
}