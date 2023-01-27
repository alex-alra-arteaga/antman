/*
** EPITECH PROJECT, 2022
** my_getbase64nbr
** File description:
** takes a base 64 and converts it to decimal
*/

#include "../../../includes/my.h"

int my_getbase64_nbr(char *base64)
{
    int decimal = 0;
    int val;
    int length = my_strlen(base64);
    for (int i = 0; i < length; i++) {
        val = (base64[i] >= '0' && base64[i] <= '9')
                ? (base64[i] - '0') : (base64[i] - '!' - 15);
        decimal += val * my_pow(64, length - i - 1);
    }
    return (decimal);
}
