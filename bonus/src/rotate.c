/*
** algo_rotate.c for  in /home/joubert/delivery/PSU_2016_tetris
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Mon Feb 20 23:13:03 2017 Joubert Miguel
** Last update Fri Mar 17 14:46:21 2017 Joubert Miguel
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include "collision.h"
#include "my.h"

int	my_strlen_d_char(char **str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

int	count_colums(char **str)
{
  int	i;
  int	j;
  int	rslt;

  rslt = i = j = 0;
  while (str[i])
    {
      while (str[i][j])
	{
	  rslt = (j > rslt) ? j : rslt;
	  j++;
	}
      j = 0;
      i++;
    }
  return (rslt + 1);
}

char		**rotate(char **piece)
{
  char		**dest;
  t_vector	axe;
  t_vector	axe2;

  if ((dest = malloc(sizeof(char *) * count_colums(piece) * 10)) == NULL)
    return (NULL);
  axe.y = axe2.x = axe2.y = 0;
  axe.x = my_strlen_d_char(piece) - 1;
  while (piece[axe.x])
    {
      dest[axe2.x] = my_memset(my_strlen_d_char(piece) * 10);
      while (axe.x >= 0)
	{
	  dest[axe2.x][axe2.y] = piece[axe.x][axe.y];
	  axe.x--, axe2.y++;
	}
      dest[axe2.x][axe2.y] = 0;
      axe2.y = 0;
      axe.x = my_strlen_d_char(piece) - 1;
      axe.y++, axe2.x++;
      if (count_colums(piece) == axe.y)
	break;
    }
  dest[axe2.x] = NULL;
  return (dest);
}
