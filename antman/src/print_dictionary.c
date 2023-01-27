/*
** EPITECH PROJECT, 2022
** antman
** File description:
** handle the precision
*/

#include "../../includes/my.h"
#include "../string.h"

int print_dictionary(struct string_s *head)
{
    struct string_s *current = head;
    if (current->next == NULL)
        return (0);
    while (current->next != NULL) {
        my_putstr(current->string);
        if (current->next->next != NULL)
            my_putchar('|');
        current = current->next;
    }
    my_putchar('\\');
    return (0);
}
