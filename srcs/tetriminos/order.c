/*
** order.c for tetris in /home/detroy_j/Documents/delivery/tetris/srcs/tetriminos
** 
** Made by detroy_j
** Login   <jean-baptiste.detroyes@epitech.eu@epitech.net>
** 
** Started on  Thu Feb 23 13:07:04 2017 detroy_j
** Last update Thu Feb 23 16:10:38 2017 detroy_j
*/

#include <string.h>
#include "tetriminos.h"

int     alpha_tri(char *s1, char *s2)
{
  char  a;
  char  b;

  while (*s1 != '\0' && *s2 != '\0')
    {
      a = *s1;
      b = *s2;
      (a >= 65 && a <= 90) ? a += 32 : 0;
      (b >= 65 && b <= 90) ? b += 32 : 0;
      if (a > b)
	return (1);
      else if (*s1 == *s2)
	{
	  s1++;
	  s2++;
	}
      else
	return (0);
    }
  return (0);
}

void    swap_element(t_game *g, t_tetrimino *now, t_tetrimino *tmp)
{
  t_tetrimino        *tmp2;

  tmp2 = now->prev;
  (tmp == g->last) ? g->last = now : 0;
  (now == g->first) ? g->first = tmp : 0;
  (tmp2 != NULL) ? tmp2->next = tmp : 0;
  (tmp->next != NULL) ? tmp->next->prev = now : 0;
  tmp->prev = tmp2;
  now->next = tmp->next;
  tmp->next = now;
  now->prev = tmp;
}

int     order(t_game *g)
{
  t_tetrimino        *now;

  now = g->first;
  if (now == NULL || g == NULL)
    return (0);
  while (now != NULL)
    {
      if (now->next == NULL)
	break;
      if (alpha_tri(now->name, now->next->name))
	{
	  swap_element(g, now, now->next);
	  now = g->first;
	}
      else
	now = now->next;
    }
  return (0);
}
