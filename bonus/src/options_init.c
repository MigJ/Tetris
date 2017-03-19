/*
** options_init.c for tetris in /home/detroy_j/Documents/delivery/tetris
** 
** Made by detroy_j
** Login   <jean-baptiste.detroyes@epitech.eu@epitech.net>
** 
** Started on  Mon Feb 20 17:59:03 2017 detroy_j
** Last update Fri Mar  3 10:56:35 2017 Joubert Miguel
*/

#include <ncurses.h>
#include <stdlib.h>
#include "options.h"

t_options	*init_options()
{
  t_options     *opts;

  if ((opts = malloc(sizeof(*opts))) == NULL)
    exit(84);
  opts->level = 1;
  opts->k_left = KEY_LEFT;
  opts->k_right = KEY_RIGHT;
  opts->k_top = KEY_UP;
  opts->k_drop = KEY_DOWN;
  opts->k_quit = 'q';
  opts->k_pause = ' ';
  opts->map_size_col = 20;
  opts->map_size_row = 30;
  opts->without_next = 0;
  opts->debug = 0;
  return (opts);
}
