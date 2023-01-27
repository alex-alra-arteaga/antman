/*
** EPITECH PROJECT, 2022
** my_pow
** File description:
** Multiplies a base to the power of the exponent
*/

double my_pow(double base, int exponent)
{
    double result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result *= base;
        }
        exponent /= 2;
        base *= base;
    }
    return result;
}
