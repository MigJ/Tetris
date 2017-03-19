/*
** options_errors.c for tetris in /home/detroy_j/Documents/delivery/tetris
** 
** Made by detroy_j
** Login   <jean-baptiste.detroyes@epitech.eu@epitech.net>
** 
** Started on  Mon Feb 20 18:12:59 2017 detroy_j
** Last update Mon Feb 20 18:13:54 2017 detroy_j
*/

#include <stdlib.h>
#include "options.h"

int	is_double_key(t_options *opts, int key)
{
  int   nb;

  nb = 0;
  (opts->k_left == key) ? nb++ : 0;
  (opts->k_right == key) ? nb++ : 0;
  (opts->k_top == key) ? nb++ : 0;
  (opts->k_drop == key) ? nb++ : 0;
  (opts->k_pause == key) ? nb++ : 0;
  (opts->k_quit == key) ? nb++ : 0;
  return ((nb == 1) ? 0 : 1);
}

void	check_error_key(t_options *opts)
{
  int   i;

  i = 0;
  (is_double_key(opts, opts->k_left)) ? i++ : 0;
  (is_double_key(opts, opts->k_right)) ? i++ : 0;
  (is_double_key(opts, opts->k_top)) ? i++ : 0;
  (is_double_key(opts, opts->k_drop)) ? i++ : 0;
  (is_double_key(opts, opts->k_pause)) ? i++ : 0;
  (is_double_key(opts, opts->k_quit)) ? i++ : 0;

  if (i != 0)
    {
      my_putstr_error("Error: Keys are used twice or more\n");
      exit(84);
    }
}
