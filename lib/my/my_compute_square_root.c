/*
** EPITECH PROJECT, 2020
** my compute square root
** File description:
** contain my compute square root
*/

int my_compute_square_root(int nb)
{
    int v = 1;

    for (int c = 0; c * c <= nb; ++c) {
        v = c * c;
        if (v == nb)
            return c;
    }
    return -1;
}
