/*
** EPITECH PROJECT, 2022
** antman
** File description:
** handle the precision
*/

#include "../../includes/my.h"

char* int_to_hex(int nb)
{
    static char hex[9];
    int i = 0;
    while (nb != 0) {
        int remainder = nb % 27;
        if (remainder < 10) {
            hex[i] = remainder + '0';
        } else {
            hex[i] = remainder - 10 + 'A';
        }
        i++;
        nb = nb / 27;
    }
    hex[i] = '\0';
    int len = i;
    for (int j = 0; j < i / 2; j++) {
        char temp = hex[j];
        hex[j] = hex[len - j - 1];
        hex[len - j - 1] = temp;
    }
    return hex;
}
