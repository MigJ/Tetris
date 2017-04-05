/*
** free.c for tetris in /home/detroy_j/Documents/delivery/PSU_2016_tetris/srcs/options
** 
** Made by detroy_j
** Login   <jean-baptiste.detroyes@epitech.eu@epitech.net>
** 
** Started on  Fri Mar  3 13:18:51 2017 detroy_j
** Last update Fri Mar  3 13:21:32 2017 detroy_j
*/

#include <stdlib.h>
#include "options.h"

void	my_free_options(t_options *opts)
{
  (opts->bin_name != NULL) ? free(opts->bin_name) : 0;
  (opts->k_left != NULL) ? free(opts->k_left) : 0;
  (opts->k_right != NULL) ? free(opts->k_right) : 0;
  (opts->k_drop != NULL) ? free(opts->k_drop) : 0;
  (opts->k_turn != NULL) ? free(opts->k_turn) : 0;
  (opts->k_quit != NULL) ? free(opts->k_quit) : 0;
  (opts->k_pause != NULL) ? free(opts->k_pause) : 0;
  free(opts);
}
