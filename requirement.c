/*
** EPITECH PROJECT, 2021
** palindrome
** File description:
** requirement.c
*/

int my_factrec_synthesis(int nb)
{
    if (nb > 12 || nb < 0)
        return 0;
    if (nb > 1)
        return (nb * my_factrec_synthesis(nb - 1));
    return 1;
}

int my_squareroot_synthesis(int nb)
{

    for (int c = 0; c * c <= nb && c < 464341; ++c)
        if (c * c == nb)
            return c;
    return -1;
}