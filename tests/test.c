/*
** EPITECH PROJECT, 2021
** B-SYN-200-PAR-2-1-palindrome-zacharie.lawson
** File description:
** test
*/

#include <stdio.h>
#include <string.h>

int my_factrec_synthesis(int nb);

int my_squareroot_synthesis(int nb);

int main(int ac, char **av)
{
    if (ac != 2)
        return 84;
    if (strcmp(av[1], "squareroot") == 0) {
        for (int c = -1; c < 101; ++c)
            printf("%d: squareroot = %d\n", c,
                my_squareroot_synthesis(c));
        return 0;
    }
    if (strcmp(av[1], "factorial") == 0) {
        for (int c = -1; c < 14; ++c)
            printf("%d: factorial = %d\n", c,
                my_factrec_synthesis(c));
        return 0;
    }
    return 84;
}