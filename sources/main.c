/*
** EPITECH PROJECT, 2021
** main
** File description:
** main function
*/

#include <stdbool.h>
#include "palindrome.h"
#include "const.h"
#include "my.h"

static int error_handle(int ac, char **av)
{
    if (ac % 2 != 1 || ac < 2) {
        my_puterror("invalid argument\n");
        return ERROR;
    }
    for (int c = 1; c < ac - 1; c += 2)
        if (!my_str_isnum(av[c+1]))
            do_invalid();
    return SUCCES;
}

static bool print_usage(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        my_printf("%s\n", usage);
        return true;
    }
    return false;
}

int main(int ac, char **av)
{
    if (print_usage(ac, av) == true)
        return SUCCES;
    if (error_handle(ac, av) == ERROR)
        return ERROR;
    return (palindrome(ac, av));
}
