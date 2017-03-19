/*
** collision.h for  in /home/joubert/delivery/PSU_2016_tetris
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Wed Feb 22 13:24:57 2017 Joubert Miguel
** Last update Wed Mar  8 14:11:48 2017 Joubert Miguel
*/

#ifndef _COLLISION_H
# define _COLLISION_H

#include "window.h"

#define COL_LEFT verify_touched_left(win.ground, game.co, 0, *piece)
#define COL_RIGHT verify_touched_right(win.ground, game.co, 0, *piece)
#define COL_DOWN verify_touched_down(win.ground, game.co, 0, *piece)
#define COL_ROTATE verify_touched_rotate(win.ground, game.co, rotate(*piece), *piece)
#define COL_WALL_LEFT 1
#define COL_WALL_RIGHT (opts->map_size_row - count_colums(*piece) - 1)
#define COL_WALL_DOWN (opts->map_size_col - 1 - my_strlen_d_char(*piece))
#define COL_WALL_ROTATE verify_place(opts, game.co, rotate(*piece))

typedef struct s_vector
{
  int	x;
  int	y;
}t_vector;

#endif /*_COLLISION_H */
