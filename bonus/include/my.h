/*
** my.h for emacs in /home/detroy_j/delivery/CPool_Day09/include
** 
** Made by jean-baptiste detroyes
** Login   <detroy_j@epitech.net>
** 
** Started on  Thu Oct 13 08:22:12 2016 jean-baptiste detroyes
** Last update Fri Mar 17 15:49:03 2017 Joubert Miguel
*/

#ifndef MY_H
#define MY_H

#include <ncurses.h>
#include <string.h>
#include "my_time.h"
#include "collision.h"
#include "options.h"
#include "game.h"

int	my_putchar(char c);
int	my_isneg(int nb);
int	my_put_nbr(int nb);
int	my_swap(int *a, int *b);
int	my_putstr(const char *str);
size_t	my_strlen(const char *s);
int	my_getnbr(char *str);
void	my_sort_int_tab(int *tab, int size);
int	my_power_rec(int nb, int power);
int	my_square_root(int nb);
int	my_is_prime(int nb);
int	my_find_prime_sup(int nb);
char	*my_strcpy(char *dest, char *src);
char	*my_strncpy(char *dest, const char *src, size_t n);
char	*my_revstr(char *str);
char	*my_strstr(char *str, char *to_find);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int n);
char	*my_strupcase(char *str);
char	*my_strlowcase(char *str);
char	*my_strcapitalize(char *str);
int	my_str_isalpha(char *str);
int	my_str_isnum(char *str);
int	my_str_islower(char *str);
int	my_str_isupper(char *str);
int	my_str_isprintable(char *str);
char    *my_strsep(char **stringp, const char *delim);
char    *my_strdup(const char *s);
int	my_showstr(char *str);
int	my_showmem(char *str, int size);
char	*my_strcat(char *dest, const char *src);
char	*my_strncat(char *dest, const char *src, size_t n);
char	*get_next_line(const int fd);
int     *my_malloc(int *p);
int     my_putchar_r(char c);
int     my_putstr_r(char *str);
int     my_put_nbr_r(int nb, int len);
int     my_putnbrbase_r(unsigned int nbr, char *base, int len);
int     my_putnbrbase_nb(unsigned int nbr, char *base, int len);
int     my_putstr_s(char *str);
int     my_putp(void *p);
int     prints(char *str, int flag, int width);
int     printi(int nb, int flag, int width);
int     printb(unsigned int nb, char *b, int flag, int width);
int     is_flag(char c);
int     is_indicator(char c);
int	my_printf(const char *format, ...);
void	load();
void	disp_piece(char **piece, t_vector co, WINDOW *ground, int color);
int	my_strlen_d_char(char **str);
char    **rotate(char **piece);
int     count_colums(char **str);
char    **empty_clear(char **piece);
int	verify_touched_down(WINDOW *ground, t_vector co, int xi, char **piece);
void    clear_line(int  line, WINDOW *ground, int col);
int	detect_full_line(WINDOW *ground, int col, int lines);
void    clear_piece(char **piece, int y, int x, WINDOW *ground);
void	init_colors();
int     verify_touched_right(WINDOW *ground, t_vector co, int yi, char **piece);
int     verify_touched_left(WINDOW *ground, t_vector co, int yi, char **piece);
int     verify_touched_rotate(WINDOW *ground, t_vector co, char **piece, char **old);
int	verify_place(t_options *opts, t_vector co, char **piece);
char    *text_to_string(char *path, int length);
char    *nb_to_ascii(int nb);
int     timer();
void    show_panel(WINDOW *panel, int score_count, int color);
t_my_time       convert_time(int nb);
t_game          key_pressed(t_options *opts, t_window win, t_game game, char ***piece);
t_game          init_game(t_game game, t_options *opts, char **piece);
t_window        init_window(t_window win, t_options *opts);
t_game          is_touched_down(t_options *opts, t_window win, t_game game, char ***piece);
t_game          key_pressed(t_options *opts, t_window win, t_game game, char ***piece);
t_game          create_new_piece(t_options *opts, t_window win, t_game game, char **piece);
void		verify_term_size();
char		*my_memset(int size);
int		verify_collision(WINDOW *ground, int x, int y);
void            window(t_options *opts, char **piece, t_window win, t_game game);

#endif
