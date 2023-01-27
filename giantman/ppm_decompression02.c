/*
** EPITECH PROJECT, 2022
** Giantman
** File description:
** Deompressing algorithm
*/

#include "../includes/my.h"
#include "../includes/giantman.h"

int find_newline(char *buffer)
{
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n') {
            return i;
        }
    }
    return -1;
}

int find_digit(char *buffer, int start_index)
{
    for (int i = start_index; buffer[i] != '\0'; i++) {
        if (buffer[i] >= '0' && buffer[i] <= '9') {
            return i;
        }
    }
    return -1;
}

int find_space(char *buffer, int start_index)
{
    for (int i = start_index; buffer[i] != '\0'; i++) {
        if (buffer[i] == ' ') {
            return i;
        }
    }
    return -1;
}

int get_pixel_start_index(char *buffer)
{
    int newline_index = find_newline(buffer);
    if (newline_index == -1)
        return 0;
    int digit_index = find_digit(buffer, newline_index + 1);
    if (digit_index == -1)
        return 0;
    int space_index = find_space(buffer, digit_index);
    if (space_index == -1)
        return 0;
    digit_index = find_digit(buffer, space_index + 1);
    if (digit_index == -1)
        return 0;
    for (int i = digit_index; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n') {
            return i + 1;
        }
    }
    return 0;
}

bool is_in_rep(char *buffer, int index)
{
    for (int i = index; buffer[i] != '\n'; i++) {
        if (buffer[i] == '~' || buffer[i - 1] == '~' || buffer[i - 2] == '~'
            || buffer[i - 3] == '~')
            return (true);
    }
    return (false);
}
