/*
** options_errors.c for tetris in /home/detroy_j/Documents/delivery/tetris
** 
** Made by detroy_j
** Login   <jean-baptiste.detroyes@epitech.eu@epitech.net>
** 
** Started on  Mon Feb 20 18:12:59 2017 detroy_j
** Last update Mon Mar  6 02:51:32 2017 detroy_j
*/

#include <stdlib.h>
#include "options.h"
#include "my.h"

int	is_double_key(t_options *opts, char *key)
{
  int	nb;

  nb = 0;
  (my_strcmp(opts->k_left, key) == 0) ? nb++ : 0;
  (my_strcmp(opts->k_right, key) == 0) ? nb++ : 0;
  (my_strcmp(opts->k_turn, key) == 0) ? nb++ : 0;
  (my_strcmp(opts->k_drop, key) == 0) ? nb++ : 0;
  (my_strcmp(opts->k_pause, key) == 0) ? nb++ : 0;
  (my_strcmp(opts->k_quit, key) == 0) ? nb++ : 0;
  return ((nb == 1) ? 0 : 1);
}

void	check_error_key(t_options *opts)
{
  int   i;

  i = 0;
  (is_double_key(opts, opts->k_left)) ? i++ : 0;
  (is_double_key(opts, opts->k_right)) ? i++ : 0;
  (is_double_key(opts, opts->k_turn)) ? i++ : 0;
  (is_double_key(opts, opts->k_drop)) ? i++ : 0;
  (is_double_key(opts, opts->k_pause)) ? i++ : 0;
  (is_double_key(opts, opts->k_quit)) ? i++ : 0;

  if (i != 0)
    {
      exit(84);
    }
}
