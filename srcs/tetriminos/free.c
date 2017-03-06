/*
** free.c for tetris in /home/detroy_j/Documents/delivery/PSU_2016_tetris/srcs/tetriminos
** 
** Made by detroy_j
** Login   <jean-baptiste.detroyes@epitech.eu@epitech.net>
** 
** Started on  Fri Mar  3 13:24:04 2017 detroy_j
** Last update Mon Mar  6 15:55:38 2017 detroy_j
*/

#include <stdlib.h>
#include "tetriminos.h"

static void	free_tetrimino(t_tetrimino *t)
{
  int		i;

  i = 0;
  (t->name != NULL) ? free(t->name) : 0;
  while (i < t->row)
    {
      if (t->shape[i] != NULL)
	free(t->shape[i]);
      if (t->d_shape[i] != NULL)
	free(t->d_shape[i]);
      i++;
    }
  free(t);
}

void	my_free_tetriminos(t_game *game)
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
  free(game);
}
