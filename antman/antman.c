/*
** EPITECH PROJECT, 2022
** antman
** File description:
** handle the precision
*/

#include <fcntl.h>
#include "string.h"
#include "../includes/my.h"
#include "../includes/giantman.h"

int error_handling_ant(int argc, char **argv)
{
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        return (84);
    if (is_directory(argv[1]))
        return (84);
    if (argc != 3) {
        my_putstr_stderr("Incorrect number of arguments\n");
        return (84);
    }
    if (argv[2][0] != '1' && argv[2][0] != '2' && argv[2][0] != '3') {
        my_putstr_stderr("Incorrect argument of file type\n");
        return (84);
    }
    return (0);
}

int main(int ac, char **av)
{
    int status = error_handling_ant(ac, av);
        if (status == 0) {
            switch (av[2][0]) {
            case '1':
                status = comp_song(av[1]);
                break;
            case '2':
                status = comp_html(av[1]);
                break;
            case '3':
                status = comp_img(av[1]);
                break;
            default:
                return (84);
        }
    }
    return (status);
}
