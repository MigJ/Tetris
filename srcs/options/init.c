/*
** options_init.c for tetris in /home/detroy_j/Documents/delivery/tetris
** 
** Made by detroy_j
** Login   <jean-baptiste.detroyes@epitech.eu@epitech.net>
** 
** Started on  Mon Feb 20 17:59:03 2017 detroy_j
** Last update Fri Mar  3 10:23:05 2017 detroy_j
*/

#include <ncurses.h>
#include <stdlib.h>
#include <term.h>
#include "options.h"

t_options	*init_options()
{
  t_options     *opts;
  int		i;

  if ((opts = malloc(sizeof(*opts))) == NULL)
    exit(84);
  i = 0;
  opts->level = DEFAULT_LEVEL;
  opts->k_left = get_no_display_key(tigetstr("kcub1"));
  opts->k_right = get_no_display_key(tigetstr("kcuf1"));
  opts->k_turn = get_no_display_key(tigetstr("kcuu1"));
  opts->k_drop = get_no_display_key(tigetstr("kcud1"));
  opts->k_quit = my_strdup(DEFAULT_KEY_QUIT);
  opts->k_pause = my_strdup(DEFAULT_KEY_PAUSE);
  while (i++ < 6)
    opts->k_defined[i] = 0;
  opts->map_size_col = DEFAULT_COL;
  opts->map_size_row = DEFAULT_ROW;
  opts->without_next = DEFAULT_WITHOUT;
  opts->debug = DEFAULT_DEBUG;
  return (opts);
}
