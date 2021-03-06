/*
** color.c for  in /home/joubert/delivery/PSU_2016_tetris
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Wed Feb 22 17:42:50 2017 Joubert Miguel
** Last update Sun Mar 19 16:41:44 2017 detroy_j
*/

#include <ncurses.h>
#include "my.h"

int	verify_collision(WINDOW *ground, int y, int x)
{
  if (mvwinch(ground, y, x) == 554
      || mvwinch(ground, y, x) == 810
      || mvwinch(ground, y, x) == 1066
      || mvwinch(ground, y, x) == 1322
      || mvwinch(ground, y, x) == 1578
      || mvwinch(ground, y, x) == 1834
      || mvwinch(ground, y, x) == 42
      || mvwinch(ground, y, x) == 298)
    return (1);
  return (0);
}

void	init_colors()
{
  start_color();
  init_pair(0, COLOR_BLACK, COLOR_BLACK);
  init_pair(1, COLOR_RED, COLOR_RED);
  init_pair(2, COLOR_GREEN, COLOR_GREEN);
  init_pair(3, COLOR_YELLOW, COLOR_YELLOW);
  init_pair(4, COLOR_BLUE, COLOR_BLUE);
  init_pair(5, COLOR_MAGENTA, COLOR_MAGENTA);
  init_pair(6, COLOR_CYAN, COLOR_CYAN);
  init_pair(7, COLOR_WHITE, COLOR_WHITE);
}
