/*
** options_errors.c for tetris in /home/detroy_j/Documents/delivery/tetris
** 
** Made by detroy_j
** Login   <jean-baptiste.detroyes@epitech.eu@epitech.net>
** 
** Started on  Mon Feb 20 18:12:59 2017 detroy_j
** Last update Thu Mar  9 15:52:00 2017 detroy_j
*/

#include <stdlib.h>
#include "options.h"
#include "my.h"

static int	is_valid_key(char *key)
{
  int		i;

  i = 0;
  (my_strcmp(key, SOPT_KEY_LEFT) == 0) ? i++ : 0;
  (my_strcmp(key, SOPT_KEY_RIGHT) == 0) ? i++ : 0;
  (my_strcmp(key, SOPT_KEY_DROP) == 0) ? i++ : 0;
  (my_strcmp(key, SOPT_KEY_TURN) == 0) ? i++ : 0;
  (my_strcmp(key, SOPT_KEY_QUIT) == 0) ? i++ : 0;
  (my_strcmp(key, SOPT_KEY_PAUSE) == 0) ? i++ : 0;
  (my_strcmp(key, OPT_KEY_LEFT) == 0) ? i++ : 0;
  (my_strcmp(key, OPT_KEY_RIGHT) == 0) ? i++ : 0;
  (my_strcmp(key, OPT_KEY_DROP) == 0) ? i++ : 0;
  (my_strcmp(key, OPT_KEY_TURN) == 0) ? i++ : 0;
  (my_strcmp(key, OPT_KEY_QUIT) == 0) ? i++ : 0;
  (my_strcmp(key, OPT_KEY_PAUSE) == 0) ? i++ : 0;
  return ((i == 0) ? 1 : 0);
}

static int	is_double_key(t_options *opts, char *key)
{
  int		nb;

  nb = 0;
  (my_strcmp(opts->k_left, key) == 0) ? nb++ : 0;
  (my_strcmp(opts->k_right, key) == 0) ? nb++ : 0;
  (my_strcmp(opts->k_turn, key) == 0) ? nb++ : 0;
  (my_strcmp(opts->k_drop, key) == 0) ? nb++ : 0;
  (my_strcmp(opts->k_pause, key) == 0) ? nb++ : 0;
  (my_strcmp(opts->k_quit, key) == 0) ? nb++ : 0;
  (is_valid_key(opts->k_left) == 0) ? nb++ : 0;
  (is_valid_key(opts->k_right) == 0) ? nb++ : 0;
  (is_valid_key(opts->k_turn) == 0) ? nb++ : 0;
  (is_valid_key(opts->k_drop) == 0) ? nb++ : 0;
  (is_valid_key(opts->k_quit) == 0) ? nb++ : 0;
  (is_valid_key(opts->k_pause) == 0) ? nb++ : 0;
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
    show_help(opts, 84);
}
