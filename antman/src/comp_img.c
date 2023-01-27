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
#include "../../includes/giantman.h"
#include <unistd.h>

int my_put_nbr_antman(int nb)
{
    if (nb < -2147483647 || nb > 2147483647)
        return (0);
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb == 0) {
        my_putchar('0');
    }
    if (nb / 10) {
        my_put_nbr_antman(nb / 10);
    }
    my_putchar(nb % 10 + '0');
    return (0);
}

char **read_image_file(char *file)
{
    struct stat sb;
    char **content;
    int fd = open(file, O_RDONLY);
    int offset = 0;
    int len;
    if (fd == -1)
        return (NULL);
    if (stat(file, &sb) == -1)
        return (NULL);
    char *buff = malloc(sizeof(char) * sb.st_size + 1);
    buff[0] = '\0';
    while ((len = read(fd, buff + offset, sb.st_size - offset)) > 0)
        offset = offset + len;
    buff[offset] = '\0';
    if (buff != NULL)
        content = my_split(buff, '\n');
    else
        return NULL;
    my_put_nbr_antman(sb.st_size);
    return (content);
}

void print_header(char **content)
{
    my_putchar('\\');
    my_putstr(content[0]), my_putchar('\n');
    my_putstr(content[1]), my_putchar('\n');
    my_putstr(content[2]), my_putchar('\n');
}

int comp_img(char *file)
{
    char **content;
    int i = 3;
    int times = 0;
    char *temp = NULL;
    content = read_image_file(file);
    if (content == NULL)
        return (84);
    print_header(content);
    comp_img_helper(content, &i, &times, &temp);
    return (0);
}
