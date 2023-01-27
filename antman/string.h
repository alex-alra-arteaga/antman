/*
** EPITECH PROJECT, 2022
** dictionary.h
** File description:
** clock structure
*/

#ifndef STRINGS_H_
    #define STRINGS_H_

    struct string_s{
    char *string;
    int index;
    struct string_s *next;
    };

#endif

#ifndef PARSE_H_
    #define PARSE_H_

    struct parse_s {
        char *string;
        int times;
    };

#endif

#define TABLE_SIZE 100
