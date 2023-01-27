/*
** EPITECH PROJECT, 2022
** antman
** File description:
** handle the precision
*/

#include <sys/stat.h>
#include <stdlib.h>
#include "string.h"
#include "../../includes/my.h"

int should_add(char *str, int index, int times)
{
    if (times > 2) {
        if (index < 10 && my_strlen(str) >= 3) {
            return (0);
        }
        if (index >= 10 && my_strlen(str) >= 4) {
            return (0);
        }
        if (index >= 19 && my_strlen(str) >= 5) {
            return (0);
        }
        return (1);
    }
    return (1);
}

void init_dict
(char **content, struct string_s *current, struct string_s *head, int j)
{
    int i = 0;
    int index = 0;
    struct parse_s *parse = malloc(sizeof(struct parse_s));
    while (content[i]) {
        parse->string = my_strdup(content[i]);
        parse->times = 0;
        while (content[j]) {
            (my_strcmp(content[j], parse->string) == 0)
            ? (parse->times += 1, j++) : (j++);
        }
        if (should_add(parse->string, index, parse->times) == 0
        && !(search_double(head, parse->string))) {
            current->string = my_strdup(parse->string);
            current->index = index;
            current->next = malloc(sizeof(struct string_s));
            current = current->next;
            index++;
        }
        free(parse->string), j = 0, i++, current->next = NULL;
    }
}

int comp_song(char *file)
{
    char **content = read_map(file);
    if (content == NULL)
        return (84);
    int j = 0;
    struct string_s *head = malloc(sizeof(struct string_s));
    struct string_s *current = head;
    current->next = NULL;

    init_dict(content, current, head, j);
    print_dictionary(head);
    print_result(head, content);
    return (0);
}
