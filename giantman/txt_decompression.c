/*
** EPITECH PROJECT, 2022
** Giantman
** File description:
** Deompressing algorithm
*/

#include "../includes/my.h"
#include "../includes/giantman.h"

parse_t parse_dict(char *buffer)
{
    int cnt = 0;
    int i = 0;
    parse_t parse;
    while (buffer[cnt++] != '\\') {

    }
    char *init_dict = malloc(sizeof(char) * cnt + 1);
    while (i < cnt) {
        init_dict[i] = buffer[i];
        i++;
    }
    init_dict[i - 1] = '\0';
    parse.dict = my_split(init_dict, '|');
    parse.index = i;
    free(init_dict);
    return (parse);
}

int get_index_dict(int index, char *buffer)
{
    int i = 0;
    int index_dict;
    char *tmp_str = malloc(sizeof(char) * 11);

    index--;
    while (is_num(buffer[index]) || (buffer[index] >= 'A'
    && buffer[index] <= '[')) {
        tmp_str[i++] = buffer[index];
        index--;
    }
    tmp_str[i] = '\0';
    char *base27_nbr = my_revstr(tmp_str);
    index_dict = my_getbase27_nbr(base27_nbr);
    free(tmp_str);
    return (index_dict);
}

char *insert_dict_word_txt
(parse_t parse, int index_dict, char *decompressed_string, int cnt)
{
    for (int j = 0; j < my_strlen(parse.dict[index_dict]); j++) {
        decompressed_string[cnt++] = parse.dict[index_dict][j];
    }
    decompressed_string[cnt] = ' ';
    return (decompressed_string);
}

int get_start_index(int cnt, char *buffer, int i)
{
    i--;
    while ((buffer[i] >= '0' && buffer[i] <= '9')
    || (buffer[i] >= 'A' && buffer[i] <= '[')) {
        cnt--;
        i--;
    }
    return (cnt);
}

void decompress_text(char *buffer)
{
    int index_dict;
    int cnt = 0;
    parse_t parse = parse_dict(buffer);
    char *deco_string = malloc(sizeof(char) * 3 * my_strlen(buffer));
    for (int i = parse.index; i < my_strlen(buffer); i++) {
        if (buffer[i] == '|'
        && ((buffer[i - 1] >= '0' && buffer[i - 1] <= '9')
        || (buffer[i - 1] >= 'A' && buffer[i - 1] <= '['))
        ) {
            index_dict = get_index_dict(i, buffer);
            cnt = get_start_index(cnt, buffer, i);
            deco_string = insert_dict_word_txt
                    (parse, index_dict, deco_string, cnt);
            cnt += my_strlen(parse.dict[index_dict]) + 1;
        } else
            deco_string[cnt++] = buffer[i];
    }
    deco_string[cnt] = '\0';
    char *output_string = change_if_last_char_is_symbol(buffer, deco_string);
    my_putstr(output_string);
}
