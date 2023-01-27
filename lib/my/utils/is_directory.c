/*
** EPITECH PROJECT, 2022
** is_directory
** File description:
** checks if string represents a folder
*/

#include <sys/stat.h>
#include <stdbool.h>

bool is_directory(char *path)
{
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISDIR(path_stat.st_mode);
}
