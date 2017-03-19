/*
** verify.c for  in /home/joubert/delivery/PSU_2016_tetris
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Tue Feb 21 02:34:23 2017 Joubert Miguel
** Last update Fri Mar 17 15:19:24 2017 Joubert Miguel
*/

#include <ncurses.h>
#include "my.h"
#include "options.h"

int		verify_place(t_options *opts, t_vector co, char **piece)
{
  t_vector	co_p;
  int		tmp;

  tmp = co.x;
  co_p.x = co_p.y = 0;
  while (piece[co_p.y])
    {
      while (piece[co_p.y][co_p.x])
	{
	  if (co.x < 0 || co.x + count_colums(piece) - 1 > opts->map_size_row)
	    return (1);
	  co_p.x++, co.x++;
	}
      co.x = tmp;
      co_p.x = 0;
      co_p.y++, co.y++;
      if (co.y + my_strlen_d_char(piece) - 1 > opts->map_size_col)
	return (1);
    }
  return (0);
}

int		verify_touched_rotate(WINDOW *ground, t_vector co,
				      char **piece, char **old)
{
  t_vector	co_p;
  int		tmp;

  tmp = co.x;
  co_p.x = co_p.y = 0;
  while (piece[co_p.y])
    {
      while (piece[co_p.y][co_p.x])
	{
	  if (co_p.x <= count_colums(old) - 1 && co_p.y <= my_strlen_d_char(old) - 1)
	    {
	      if ((verify_collision(ground, co.y, co.x) == 1)
		  && old[co_p.y][co_p.x] != 42)
		return (1);
	    }
	  else if (verify_collision(ground, co.y, co.x) == 1)
	    return (1);
	  co_p.x++, co.x++;
	}
      co_p.x = 0;
      co.x = tmp;
      co.y++, co_p.y++;
    }
  return (0);
}

int		verify_touched_left(WINDOW *ground, t_vector co, int yi, char **piece)
{
  int		xi;
  int		tmp;

  tmp = co.x;
  xi = 0;
  while (piece[yi][xi] != '*')
    xi++, co.x++;
  if (verify_collision(ground, co.y, co.x - 1) == 1)
    return (1);
  co.y++;
  co.x = tmp;
  if (++yi != my_strlen_d_char(piece))
    return (verify_touched_left(ground, co, yi, piece));
  return (0);
}

int		verify_touched_right(WINDOW *ground, t_vector co, int yi, char **piece)
{
  int		xi;
  int		tmp;

  co.x += count_colums(piece) - 1;
  tmp = co.x;
  xi = count_colums(piece) - 1;
  while (piece[yi][xi] != '*')
    xi--, co.x--;
  if (verify_collision(ground, co.y, co.x + 1) == 1)
    return (1);
  co.y++;
  co.x = tmp;
  if (++yi != my_strlen_d_char(piece))
    return (verify_touched_right(ground, co, yi, piece));
  return (0);
}

int		verify_touched_down(WINDOW *ground, t_vector co, int xi, char **piece)
{
  int		yi;
  int		tmp;

  tmp = co.y;
  co.y += my_strlen_d_char(piece) - 1;
  yi = my_strlen_d_char(piece) - 1;
  while (piece[yi][xi] != '*')
    yi--, co.y--;
  if (verify_collision(ground, co.y + 1, co.x) == 1)
    return (1);
  co.x++;
  co.y = tmp;
  if (xi++ != count_colums(piece) - 1)
    return (verify_touched_down(ground, co, xi++, piece));
  return (0);
}
