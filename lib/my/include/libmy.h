/*
** EPITECH PROJECT, 2021
** MY H
** File description:
** Library header
*/

#ifndef MY_H_
    #define MY_H_

    #include <stdarg.h>
    #include <stdio.h>
    #include <getopt.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <dirent.h>
    #include <signal.h>
    #include <sys/types.h>
    #include <stdbool.h>
    #include <sys/stat.h>
    #include <fcntl.h>

    #define char_is_lower(c) (c >= 'a' && c <= 'z')
    #define char_is_upper(c) (c >= 'A' && c <= 'Z')
    #define char_is_num(c) (c >= '0' && c <= '9')
    #define char_is_alpha(c) (char_is_lower(c) || char_is_upper(c))
    #define char_is_alphanum(c) (char_is_alpha(c) || char_is_num(c))

    const char *my_strstr(const char *X, const char *Y);
    bool my_str_isnum(char const *str);
    unsigned int nl_counter(char const *input);
    char *get_file(char *filename);
    int **my_intarrmalloc(int x, int y);
    int *my_intmalloc(int len);
    unsigned int line_length(char const *input);
    char *read_file(char *str);
    char *my_itoa(int n, char *s);
    char *read_line(FILE *stream);
    void my_putarr(char **arr, char *sep);
    void my_putstr(char const *str);
    void my_puterror(char const *str);
    int ***my_3int_arrmalloc(int x, int y, int z);
    char **my_arrmalloc(int x, int y);
    void *check_malloc(size_t size);
    char **my_arrdup(char **src);
    int my_arrlen(char **arr);
    int my_atoi(char const *str);
    float my_atof(char const *str);
    int my_strlen(char const *str);
    bool my_str_isnum(char const *str);
    char *my_strmalloc(int len);
    void my_strreplace(char *str, char replaced, char replacer);
    int my_getnbr(char const *str);
    int my_strcmp(char const *s1, char const *s2);
    int my_strncmp(char const *s1, char const *s2, int n);
    int count_chars(char *str, char letter);
    char **my_stoa(char *str, char sep);
    void my_putchar(char c);
    int my_printf(char *format, ...);
    int my_intlen(int nb);
    void my_put_address(unsigned long nb);
    unsigned long long int get_bin(int nb);
    char *dec_to_bin(unsigned int dec);
    char *dec_to_oct(unsigned int dec);
    void my_putnbr(int nb);
    void my_putnbr_base(int nb, char *base);

#endif
