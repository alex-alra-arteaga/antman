/*
** EPITECH PROJECT, 2022
** Giantman
** File description:
** Deompressing algorithm
*/

#include "../includes/my.h"
#include "../includes/giantman.h"

int length_encoded_base(char *buffer, int index)
{
    int len = 0;
    for (int i = index; buffer[i] != '\n'; i++) {
        len++;
    }
    return (len);
}

int print_decompress(char *buffer, int i)
{
    if (buffer[i - 1] == '\n' && rest_is_repe(buffer, i)) {
        insert_base64_nbr_repe(buffer, i);
    } else if (buffer[i - 1] == '\n' && !rest_is_repe(buffer, i)) {
        insert_base64_nbr(buffer, i);
        i += length_encoded_base(buffer, i);
    } else {
        if (buffer[i] != '\n' && !is_in_rep(buffer, i))
            my_putchar(buffer[i]);
    }
    return (i);
}

void decompress_ppm(char *buffer)
{
    int j = 0;

    int index_pixels = get_pixel_start_index(buffer);
    while (buffer[j++] != '\\') {

    }
    for (int c = j; c < index_pixels; c++) {
        my_putchar(buffer[c]);
    }
    for (int i = index_pixels; buffer[i]; i++) {
        i = print_decompress(buffer, i);
    }
}

int main(int argc, char **argv)
{
    status_t info;
    bool error = error_handling(argc, argv);
    if (!error)
        info = open_n_read_compression(argv);
    if (!error && !info.error) {
        switch (argv[2][0]) {
            case '1':
                decompress_text(info.buff); break;
            case '2':
                decompress_html(info.buff); break;
            case '3':
                decompress_ppm(info.buff); break;
            default:
                return (84);
        }
    } else
        return (84);
    free(info.buff);
    return (0);
}
