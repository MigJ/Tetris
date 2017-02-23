/*
** options_init.c for tetris in /home/detroy_j/Documents/delivery/tetris
** 
** Made by detroy_j
** Login   <jean-baptiste.detroyes@epitech.eu@epitech.net>
** 
** Started on  Mon Feb 20 17:59:03 2017 detroy_j
** Last update Wed Feb 22 17:48:06 2017 detroy_j
*/

#include <ncurses.h>
#include <stdlib.h>
#include "options.h"

t_options	*init_options()
{
  t_options     *opts;

  if ((opts = malloc(sizeof(*opts))) == NULL)
    exit(84);
  opts->level = DEFAULT_LEVEL;
  opts->k_left = KEY_LEFT;
  opts->k_right = KEY_RIGHT;
  opts->k_turn = KEY_UP;
  opts->k_drop = KEY_DOWN;
  opts->k_quit = DEFAULT_KEY_QUIT;
  opts->k_pause = DEFAULT_KEY_PAUSE;
  opts->map_size_col = DEFAULT_COL;
  opts->map_size_row = DEFAULT_ROW;
  opts->without_next = DEFAULT_WITHOUT;
  opts->debug = DEFAULT_DEBUG;
  return (opts);
}
