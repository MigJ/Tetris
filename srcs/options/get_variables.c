/*
** options_get_variables.c for tetris in /home/detroy_j/Documents/delivery/tetris
** 
** Made by detroy_j
** Login   <jean-baptiste.detroyes@epitech.eu@epitech.net>
** 
** Started on  Mon Feb 20 18:11:26 2017 detroy_j
** Last update Tue Feb 28 18:20:52 2017 detroy_j
*/

#include <stdlib.h>
#include "options.h"
#include "my.h"

void	set_start_level(t_options *opts, char *value)
{
  int   nb;

  if (!is_number(value))
    show_help(opts, 84);
  nb = my_getnbr(value);
  if (nb < 1)
    show_help(opts, 84);
  opts->level = nb;
}

void	set_map_size(t_options *opts, char *value)
{
  char  *str;
  int   col;
  int   row;

  str = NULL;
  if (!have_comma(value))
    show_help(opts, 84);
  str = my_strsep(&value, ",");
  if (!is_number(value) || !is_number(str))
    show_help(opts, 84);
  row = my_getnbr(str);
  col = my_getnbr(value);
  if (row < 1 || col < 1)
    show_help(opts, 84);
  opts->map_size_row = row;
  opts->map_size_col = col;
}
