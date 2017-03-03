/*
** options_get_keys.c for tetris in /home/detroy_j/Documents/delivery/tetris
** 
** Made by detroy_j
** Login   <jean-baptiste.detroyes@epitech.eu@epitech.net>
** 
** Started on  Mon Feb 20 18:07:36 2017 detroy_j
** Last update Fri Mar  3 10:26:56 2017 detroy_j
*/

#include <stdlib.h>
#include <curses.h>
#include <term.h>
#include <stdio.h>
#include "options.h"

void	set_key_left(t_options *opts, char *value)
{
  if (opts->k_defined[0] == 1)
    show_help(opts, 84);
  opts->k_left = value;
  opts->k_defined[0] = 1;
}

void	set_key_right(t_options *opts, char *value)
{
  if (opts->k_defined[1] == 1)
    show_help(opts, 84);
  opts->k_right = value;
  opts->k_defined[1] = 1;
}

void	set_key_drop(t_options *opts, char *value)
{
  if (opts->k_defined[2] == 1)
    show_help(opts, 84);
  opts->k_drop = value;
  opts->k_defined[2] = 1;
}

void	set_key_turn(t_options *opts, char *value)
{
  if (opts->k_defined[3] == 1)
    show_help(opts, 84);
  opts->k_turn = value;
  opts->k_defined[3] = 1;
}
