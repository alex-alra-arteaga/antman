/*
** EPITECH PROJECT, 2022
** Giantman
** File description:
** Deompressing algorithm
*/

#include "../includes/my.h"
#include "../includes/giantman.h"

status_t open_n_read_compression_ppm(char **argv)
{
    struct stat sb;
    int offset = 0;
    int len;
    int fd = open(argv[1], O_RDONLY);
    status_t status = (status_t) {.error = false, .buff = NULL};
    if (fd < 0) {
        my_putstr_stderr("Error opening input file");
        status.error = true;
    }
    stat(argv[1], &sb);
    status.buff = malloc(sizeof(char) * sb.st_size + 1);
    status.buff[0] = '\0';
    while ((len = read(fd, status.buff + offset, sb.st_size - offset)) > 0)
        offset += len;
    status.buff[offset] = '\0';
    if (len < 0) {
        free(status.buff);
        status.error = true;
    }
    return (status);
}

char *get_size_str(char *buffer)
{
    int i = 0;
    char *size_str = malloc(sizeof(char) * 11);

    while (buffer[i] != '\\') {
        size_str[i] = buffer[i];
        i++;
    }
    size_str[i] = '\0';
    return (size_str);
}

bool rest_is_repe(char *buffer, int j)
{
    for (int i = j; buffer[i] != '\n'; i++) {
        if (buffer[i] == '~')
            return (true);
    }
    return (false);
}

void insert_base64_nbr(char *buffer, int index)
{
    int j = 0;
    char *tmp_str = malloc(sizeof(char) * 11);

    for (int i = index; buffer[i] != '\n'; i++) {
        tmp_str[j++] = buffer[i];
    }
    tmp_str[j] = '\0';
    int base94_nbr = my_getbase64_nbr(tmp_str);
    char *base94_str = my_int_to_str(base94_nbr);
    for (int c = 0; base94_str[c]; c++) {
        my_putchar(base94_str[c]);
    }
    my_putchar('\n');
}

void insert_base64_nbr_repe(char *buffer, int index)
{
    int j = 0;
    char *tmp_str = malloc(sizeof(char) * 11);
    char *tmp_str02 = malloc(sizeof(char) * 11);

    while (buffer[index] != '~') {
        tmp_str[j++] = buffer[index++];
    }
    tmp_str[j] = '\0';
    j = 0;
    while (buffer[++index] != '\n')
        tmp_str02[j++] = buffer[index];
    tmp_str02[j] = '\0';
    char *base93_nbr = my_int_to_str(my_getbase64_nbr(tmp_str));
    int repeated_nbr = my_getbase64_nbr(tmp_str02);
    for (int c = 0; c < repeated_nbr; c++) {
        for (int i = 0; base93_nbr[i]; i++) {
            my_putchar(base93_nbr[i]);
        }
        my_putchar('\n');
    }
}
