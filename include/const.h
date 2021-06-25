/*
** EPITECH PROJECT, 2021
** cont.h
** File description:
** const.h
*/

#ifndef _CONST_H_
#define _CONST_H_

static const int ERROR = 84;
static const int NO_ERROR = 0;
static const int SUCCES = 0;

static const char *nflag = "-n";
static const char *pflag = "-p";
static const char *bflag = "-b";
static const char *min = "-imin";
static const char *max = "-imax";

static const char *usage = "USAGE\n\t./palindrome -n nb -p pal [-b base] "
    "[-imin i] [-imax i]\n\nDESCRIPTION\n\t-n n\t integer to be "
    "transformed (>=0)\n\t-p pal\t palindromic number to be obtained "
    "(incompatible with the -n option) (>=0)\n\t\t if defined, all fitting "
    "value of n will be output\n\t-b base\t base in which the procedure will "
    "be executed (1<b<10) [def:10]\n\t-imin i\t minimum number of iterations, "
    "included (>=0) [def: 0]\n\t-imax i\t maximum number of iterations, "
    "included (>=0) [def: 100]";

#endif
