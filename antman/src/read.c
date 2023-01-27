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
#include <unistd.h>
#include <stdio.h>
#include <string.h>

char **read_map(char *file)
{
    struct stat sb;
    char *buff;
    char **content;
    int fd = open(file, O_RDONLY);
    if (fd == -1)
        return (NULL);
    int offset = 0;
    int len;
    if (stat(file, &sb) == -1)
        return (NULL);
    buff = malloc(sizeof(char) * sb.st_size + 1);
    buff[0] = '\0';
    while ((len = read(fd, buff + offset, sb.st_size - offset)) > 0)
        offset = offset + len;
    buff[offset] = '\0';
    if (buff != NULL)
        (content = my_split(buff, ' '));
    else
        return (NULL);
    return (content);
}
