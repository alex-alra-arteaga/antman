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


bool search_double(struct string_s *head, char *string)
{
    struct string_s *current = head;
    while (current->next != NULL) {
        if (my_strcmp(string, current->string) == 0) {
            return (true);
        }
        current = current->next;
    }
    return (false);
}
