/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** Contains the prototypes of all the functions in libmy.a
*/

#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Window/Mouse.h>
#include <SFML/System/Clock.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/VideoMode.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <SFML/Window/Window.h>
#include <stddef.h>
#include <stdlib.h>
#include "../antman/string.h"

#ifndef MY_H_
    #define MY_H_

void *my_memcpy(void *dest, const void *src, size_t size);
void my_putchar_stderr(char c);
char *handles_num(char *arr, int number);
char* handles_decimal_hex(double nb);
char* cat_str(char* main_str, char* temp_str);
char* get_octal(int num, int* arr, char* temp, char* format);
int len_ulong_long(char const *str);
char *my_revstr_ulong_long(char *str);
sfRenderWindow *create_my_window(unsigned int width, unsigned int height);
int if_hexadecimal(char const *str, int cnt_1);
int is_char_alpha(char c);
int num_words(char const *str, int i, int cnt);
char **my_str_to_word_array(char const *str);
char **my_split(char const *str, char split);
int string(char const *str);
int change_sign(int sign, int number);
int get_sign_before_int(int i, char const *str, int sign);
int prevent_under_overflow(char *aux, int i, int number, int number1);
char *strlowcase02(char *str);
int compare_and_swap(int *array, int temp);
char *same_strs (char *str, char const *to_find, int index);
int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int my_getnbr(char const *str);
int my_isneg(int n);
int my_printf(char *format, ...);
int my_is_prime(int nb);
char **my_arrdup(char **src, int size);
char *my_int_to_str(int num);
void my_putchar(char c);
char my_put_nbr(int nb);
int change_sign(int sign, int number);
int my_getnbr(char const *str);
int get_sign_before_int(int i, char const *str, int sign);
int prevent_under_overflow(char *aux, int i, int number, int number1);
int my_putstr(char const *str);
int my_putstr_stderr(char const *str);
char *my_revstr(char *str);
int my_showmem(char const *str, int size);
int my_showstr(char const *str);
void my_sort_int_array(int *array, int size);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
char *my_strdup(char const *src);
int my_strcmp (char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);
bool is_num(char c);
bool is_float(char *str);
bool is_only_num(char *str);
char *strcat_malloc(char *dest, char const *src);
bool is_special_float(char *str, int nb);
char *special_float(char *string, int nb);
char *precision_int(char* string, int nb);
double my_pow(double base, int exponent);
// ! new functions
bool search_double(struct string_s *head, char *string);
int my_strcmp(const char* s1, const char* s2);
void print_result(struct string_s *head, char **content);
char* int_to_hex(int nb);
int print_dictionary(struct string_s *head);
char **read_map(char *file);
int should_add(char *str, int index, int times);
int comp_song(char *file);
int comp_html(char *file);
// ! new functions
char* int_to_64(int nb);
int comp_img(char *file);
int my_getbase27_nbr(char *base27);
int my_getbase64_nbr(char *base64);
void comp_img_helper(char **content, int *i, int *times, char **temp);
bool is_directory(char *path);
#endif /* MY_H_ */
