/*
** EPITECH PROJECT, 2022
** my_getbase27nbr
** File description:
** takes a base 27 and converts it to decimal
*/

#include "../../../includes/my.h"

int my_getbase27_nbr(char *base27)
{
    int decimal = 0;
    int val;
    int length = my_strlen(base27);
    for (int i = 0; i < length; i++) {
        val = (base27[i] <= '9') ? (base27[i] - '0') : (base27[i] - 'A' + 10);
        decimal += val * my_pow(27, length - i - 1);
    }
    return (decimal);
}
