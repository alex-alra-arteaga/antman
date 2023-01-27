/*
** EPITECH PROJECT, 2022
** My_Radar
** File description:
** The air traffic control panel
*/

#include "my.h"

#ifndef GIANTMAN_H_
    #define GIANTMAN_H_

    typedef struct s_status {
        bool error;
        char *buff;
    } status_t;

    typedef struct s_parse {
        char **dict;
        int index;
    } parse_t;

    typedef struct s_error {
        bool error;
    }error_t;

    char *insert_dict_word_txt
    (parse_t parse, int index_dict, char *decompressed_string, int cnt);
    char *insert_dict_word_html
    (char **dict, int index_dict, char *decompressed_string, int cnt);
    bool error_handling(int argc, char **argv);
    status_t open_n_read_compression(char **argv);
    parse_t parse_dict(char *buffer);
    int get_index_dict(int index, char *buffer);
    void decompress_text(char *buffer);
    void decompress_text(char *buffer);
    char *change_if_last_char_is_symbol
    (char *buffer, char *decompressed_string);
    int my_getbase94_nbr(char *base94);
    int find_newline(char *buffer);
    void decompress_html(char *buffer);
    status_t open_n_read_compression_ppm(char **argv);
    char *get_size_str(char *buffer);
    bool rest_is_repe(char *buffer, int j);
    void insert_base64_nbr(char *buffer, int index);
    void insert_base64_nbr_repe(char *buffer, int index);
    int find_newline(char *buffer);
    int find_digit(char *buffer, int start_index);
    int find_space(char *buffer, int start_index);
    int get_pixel_start_index(char *buffer);
    bool is_in_rep(char *buffer, int index);

#endif
