/*
** options_get_keys_bis.c for tetris in /home/detroy_j/Documents/delivery/tetris
** 
** Made by detroy_j
** Login   <jean-baptiste.detroyes@epitech.eu@epitech.net>
** 
** Started on  Mon Feb 20 18:10:03 2017 detroy_j
** Last update Fri Mar  3 10:27:25 2017 detroy_j
*/

#include <stdlib.h>
#include "options.h"

void	set_key_quit(t_options *opts, char *value)
{
  if (opts->k_defined[4] == 1)
    show_help(opts, 84);
  opts->k_quit = value;
  opts->k_defined[4] = 1;
}

void	set_key_pause(t_options *opts, char *value)
{
  if (opts->k_defined[5] == 1)
    show_help(opts, 84);
  opts->k_pause = value;
  opts->k_defined[5] = 1;
}
