/*
** EPITECH PROJECT, 2022
** Giantman
** File description:
** Deompressing algorithm
*/

#include "../includes/my.h"
#include "../includes/giantman.h"

bool error_handling(int argc, char **argv)
{
    bool error = false;
    if (argc != 3) {
        my_putstr_stderr("Incorrect number of arguments\n");
        error = true;
    }
    if (is_directory(argv[1]))
        my_putstr_stderr("Argument has file type of folder\n");
        error = true;
    if (argv[2][0] != '1' && argv[2][0] != '2' && argv[2][0] != '3') {
        my_putstr_stderr("Incorrect argument of file type\n");
        error = true;
    }
    return (error);
}

char *insert_dict_word_html
(char **dict, int index_dict, char *decompressed_string, int cnt)
{
    for (int j = 0; j < my_strlen(dict[index_dict]); j++) {
        decompressed_string[cnt++] = dict[index_dict][j];
    }
    return (decompressed_string);
}

char *goto_last_space(char *decompressed_string)
{
    for (int j = 0; decompressed_string[j]; j++) {
        if (decompressed_string[j] == ' '
        && decompressed_string[j + 1] == '\0') {
            decompressed_string[j] = '\0';
        }
    }
    return (decompressed_string);
}

char *change_if_last_char_is_symbol(char *buffer, char *decompressed_string)
{
    for (int i = 0; buffer[i]; i++) {
        if (buffer[i] == '|' && buffer[i + 1] == '\0') {
            decompressed_string = goto_last_space(decompressed_string);
        }
    }
    return (decompressed_string);
}

status_t open_n_read_compression(char **argv)
{
    struct stat sb;
    int offset = 0;
    int len;
    int fd;
    status_t status = (status_t){.error = false, .buff = NULL};

    fd = open(argv[1], O_RDONLY);
    if (stat(argv[1], &sb) == -1) {
        status.error = true;
        return (status);
    }
    status.buff = malloc(sizeof(char) * sb.st_size + 1);
    status.buff[0] = '\0';
    while ((len = read(fd, status.buff + offset, sb.st_size - offset)) > 0)
        offset = offset + len;
    if (status.buff == NULL || status.buff[0] == '\0')
        status.error = true;
    status.buff[offset] = '\0';
    return (status);
}
