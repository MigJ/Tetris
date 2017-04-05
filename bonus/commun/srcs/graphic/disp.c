/*
** disp.c for  in /home/joubert/delivery/PSU_2016_tetris
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Tue Feb 21 00:22:51 2017 Joubert Miguel
** Last update Fri Mar 17 15:49:37 2017 Joubert Miguel
*/

#include <string.h>
#include <stdlib.h>
#include <ncurses.h>
#include "my.h"

int	detect_full_line(WINDOW *ground, int col, int lines)
{
  int	x;
  int	y;
  int	count;

  count = y = x = 0;
  while (y != col + 1)
    {
      while (x != lines + 1)
	{
	  if (verify_collision(ground, y, x) == 1)
	    count++;
	  if (count == lines - 2)
	    return (y);
	  x++;
	}
      count = x = 0;
      y++;
    }
  return (-1);
}

void		clear_line(int	line, WINDOW *ground, int col)
{
  t_vector	axe;
  int		color;

  color = 1;
  axe.x = axe.y = -1;
  while (++axe.y != line);
  while (axe.y != 1)
    {
      while (++axe.x != col)
	{
	  if (mvwinch(ground, axe.y - 1, axe.x) == 554) color = 2;
	  else if (mvwinch(ground, axe.y - 1, axe.x) == 810) color = 3;
	  else  if (mvwinch(ground, axe.y - 1, axe.x) == 1066) color = 4;
	  else if (mvwinch(ground, axe.y - 1, axe.x) == 1322) color = 5;
	  else if (mvwinch(ground, axe.y - 1, axe.x) == 1578) color = 6;
	  else if (mvwinch(ground, axe.y - 1, axe.x) == 1834) color = 7;
	  else if (mvwinch(ground, axe.y - 1, axe.x) == 42) color = 1;
	  else if (mvwinch(ground, axe.y - 1, axe.x) == 298) color = 1;
	  wattron(ground, COLOR_PAIR(color));
	  mvwprintw(ground, axe.y, axe.x, "%c", mvwinch(ground, axe.y - 1, axe.x));
	  wattroff(ground, COLOR_PAIR(color));
	}
      axe.x = -1;
      axe.y--;
    }
}

char	**empty_clear(char **piece)
{
  int	i;
  int	j;
  t_vector emp;
  char	**empty;

  if ((empty = malloc(sizeof(char *) *
		      (my_strlen_d_char(piece) * 10))) == NULL)
    return (NULL);
  emp.x = emp.y = i = j = 0;
  while (piece[i])
    {
      empty[emp.y] = my_memset(count_colums(piece) * 10);
      while (piece[i][j])
	{
	  (piece[i][j] == '*') ? empty[emp.y][emp.x] = ' ', emp.x++ : 0;
	  j++;
	}
      empty[emp.y][emp.x] = 0;
      emp.x = j = 0;
      i++, emp.y++;
    }
  empty[emp.y] = NULL;
  return (empty);
}

void	clear_piece(char **piece, int y, int x, WINDOW *ground)
{
  int   yi;
  int   xi;
  int   tmp;

  tmp = x;
  xi = yi = 0;
  while (piece[yi])
    {
      while (piece[yi][xi])
	{
	  if (y > 0 && piece[yi][xi] != ' ')
	    mvwprintw(ground, y, x, "%c", ' ');
	  x++, xi++;
	}
      xi = 0;
      x = tmp;
      yi++, y++;
    }
}

void	disp_piece(char **piece, t_vector co, WINDOW *ground, int color)
{
  int	yi;
  int	xi;
  int	tmp;

  tmp = co.x;
  xi = yi = 0;
  while (piece[yi])
    {
      while (piece[yi][xi])
	{
	  if (co.y > 0 && piece[yi][xi] != ' ')
	    {
	      wattron(ground, COLOR_PAIR(color));
	      mvwprintw(ground, co.y, co.x, "%c", piece[yi][xi]);
	      wattroff(ground, COLOR_PAIR(1));
	    }
	  co.x++, xi++;
	}
      xi = 0;
      co.x = tmp;
      yi++, co.y++;
    }
}
