/*
** free.c for tetris in /home/detroy_j/Documents/delivery/PSU_2016_tetris/srcs/tetriminos
** 
** Made by detroy_j
** Login   <jean-baptiste.detroyes@epitech.eu@epitech.net>
** 
** Started on  Fri Mar  3 13:24:04 2017 detroy_j
** Last update Sun Mar 19 15:20:53 2017 detroy_j
*/

#include <stdlib.h>
#include "tetriminos.h"

static void	free_tetrimino(t_tetrimino *t)
{
  int		i;

  i = 0;
  (t->name != NULL) ? free(t->name) : 0;
  while (i < t->row && t->valid > 0)
    {
      if (t->shape[i] != NULL)
	free(t->shape[i]);
      if (t->d_shape[i] != NULL)
	free(t->d_shape[i]);
      i++;
    }
  if (t != NULL)
    free(t);
}

void	my_free_tetriminos(t_g *game)
{
  t_tetrimino	*now;
  t_tetrimino	*tmp;

  now = game->first;
  while (now != NULL)
    {
      tmp = now;
      now = now->next;
      free_tetrimino(tmp);
    }
  if (game != NULL)
    free(game);
}
