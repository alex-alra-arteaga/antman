/*
** EPITECH PROJECT, 2022
** Giantman
** File description:
** Deompressing algorithm
*/

#include "../includes/my.h"
#include "../includes/giantman.h"

void decompress_html(char *buffer)
{
    int index_dict;
    int cnt = 0;
    char **dict = my_split(buffer, '\n');
    char *decompressed_string = malloc(sizeof(char) * 3 * my_strlen(buffer));
    for (int i = 0; buffer[i]; i++) {
        if (buffer[i] == '^'
            && ((buffer[i - 1] >= '0' && buffer[i - 1] <= '9')
                || (buffer[i - 1] >= 'A' && buffer[i - 1] <= '['))
                ) {
            index_dict = get_index_dict(i, buffer);
            decompressed_string = insert_dict_word_html
                    (dict, index_dict, decompressed_string, cnt);
            cnt += my_strlen(dict[index_dict]) + 1;
        } else
            decompressed_string[cnt++] = buffer[i];
    }
    decompressed_string[cnt] = '\0';
    char *output_string = change_if_last_char_is_symbol
            (buffer, decompressed_string);
    my_putstr(output_string);
}
