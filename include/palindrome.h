/*
** EPITECH PROJECT, 2021
** my prog.h
** File description:
** .h file for prog
*/

#ifndef _PALINDROME_H_
#define _PALINDROME_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include "my.h"

typedef struct core_s {
    int n;
    int p;
    int b;
    int nflag;
    int pflag;
    int min;
    int max;
    int tmp;
    int flag;
} core_t;

int palindrome(int ac, char **av);
core_t *init_struct(void);
void do_invalid(void);
char *base_converter(int nb, int base);
int base_to_decim(char *str, int base);
bool check_palindrome(int nb, int base);
void do_npalindrome(core_t *core);
void do_ppalindrome(core_t *core);
void parse_flag(int ac, char **av, core_t *core);

#endif