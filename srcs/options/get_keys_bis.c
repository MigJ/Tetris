/*
** options_get_keys_bis.c for tetris in /home/detroy_j/Documents/delivery/tetris
** 
** Made by detroy_j
** Login   <jean-baptiste.detroyes@epitech.eu@epitech.net>
** 
** Started on  Mon Feb 20 18:10:03 2017 detroy_j
** Last update Wed Mar  1 15:28:32 2017 detroy_j
*/

#include <stdlib.h>
#include "options.h"

void	set_key_quit(t_options *opts, char *value)
{
  /*int   nb;

  nb = *value;
  if (nb == 0)
  exit(84);*/
  opts->k_quit = value;
}

void	set_key_pause(t_options *opts, char *value)
{
  /*int   nb;

  nb = *value;
  if (nb == 0)
  exit(84);*/
  opts->k_pause = value;
}
