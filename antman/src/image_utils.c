/*
** EPITECH PROJECT, 2022
** antman
** File description:
** handle the precision
*/

#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include "string.h"
#include "../../includes/my.h"
#include <unistd.h>

void print_same(char **content, char *temp, int times, int i)
{
    if (times != 0) {
        my_putstr(int_to_64(my_getnbr(temp)));
        my_putchar('~');
        my_putstr(int_to_64(times + 1));
        free(temp);
        if (content[i + 1] == NULL)
            my_putchar('\n');
    } else {
        if (my_strcmp(content[i], "0") == 0)
            my_putchar('0');
        else
            my_putstr(int_to_64(my_getnbr(content[i])));
    }
}

void check_same(char **content, int *i, char **temp, int *times)
{
    if (content[*i + 1] != NULL) {
        while (my_strcmp(content[*i], content[*i + 1]) == 0) {
            *temp = my_strdup(content[*i]);
            (*times)++;
            (*i)++;
        }
    }
}

void comp_img_helper(char **content, int *i, int *times, char **temp)
{
    while (content[*i]) {
        check_same(content, i, temp, times);
        print_same(content, *temp, *times, *i);
        if (content[*i + 1] != NULL)
            my_putchar('\n');
        (*i)++;
        *times = 0;
    }
}
