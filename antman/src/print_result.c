/*
** EPITECH PROJECT, 2022
** antman
** File description:
** handle the precision
*/

#include "string.h"
#include "../../includes/my.h"
#include "../string.h"
#include "stdbool.h"

void print_result(struct string_s *head, char **content)
{
    int i = 0; int j = 0;
    int index = 0;
    bool in_list = false;
    struct string_s *current = head;
    while (content[i]) {
        while (current->next != NULL) {
            (my_strcmp(content[i], current->string) == 0)
            ? (in_list = true, index = current->index) : (j ++);
            current = current->next;
        }
        current = head;
        if (in_list)
            (index == 0) ? (my_putchar('0'), my_putchar('|'))
            : (my_putstr(int_to_hex(index)), my_putchar('|'));
        else
            (content[i + 1] != NULL) ?
            (my_putstr(content[i]), my_putchar(' '))
            : (my_putstr(content[i]));
        in_list = false, i++, index = 0;
    }
}
