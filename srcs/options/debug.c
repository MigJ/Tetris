/*
** debug.c for tetris in /home/detroy_j/Documents/delivery/tetris
** 
** Made by detroy_j
** Login   <jean-baptiste.detroyes@epitech.eu@epitech.net>
** 
** Started on  Mon Feb 20 18:15:33 2017 detroy_j
** Last update Mon Mar  6 16:43:10 2017 detroy_j
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"
#include "options.h"
#include "tetriminos.h"

static char	*get_key_name(char *str)
{
  if (my_strcmp(str, DEFAULT_KEY_PAUSE) == 0)
    return (_KEY_SPACE);
  return (str);
}

static void	print_tetrimino(t_tetrimino *t)
{
  int	i;

  i = 0;
  my_putstr("Tetriminos :  Name ");
  my_putstr(t->name);
  my_putstr(" :  Size ");
  my_put_nbr(t->col);
  my_putchar('*');
  my_put_nbr(t->row);
  my_putstr(" :  Color ");
  my_put_nbr(t->color);
  my_putstr(" :\n");
  while (i < t->row)
    {
      my_putstr(t->d_shape[i++]);
      my_putchar('\n');
    }
}

static void	debug_tetriminos(t_game *game)
{
  t_tetrimino   *now;

  now = game->first;
  while (now != NULL)
    {
      if (now->valid == 0)
	{
	  my_putstr("Tetriminos :  Name ");
	  my_putstr(now->name);
	  my_putstr(" :  Error\n");
	}
      else
	print_tetrimino(now);
      now = now->next;
    }
}

void	show_debug(t_game *game, t_options *opts)
{
  my_putstr("*** DEBUG MODE ***\nKey Left :  ");
  my_putstr(get_key_name(opts->k_left));
  my_putstr("\nKey Right :  ");
  my_putstr(get_key_name(opts->k_right));
  my_putstr("\nKey Turn :  ");
  my_putstr(get_key_name(opts->k_turn));
  my_putstr("\nKey Drop :  ");
  my_putstr(get_key_name(opts->k_drop));
  my_putstr("\nKey Quit :  ");
  my_putstr(get_key_name(opts->k_quit));
  my_putstr("\nKey Pause :  ");
  my_putstr(get_key_name(opts->k_pause));
  (opts->without_next == 0) ? my_putstr("\nNext :  Yes\n")
    : my_putstr("\nNext :  No\n");
  my_putstr("Level :  ");
  my_put_nbr(opts->level);
  my_putstr("\nSize :  ");
  my_put_nbr(opts->map_size_row);
  my_putchar('*');
  my_put_nbr(opts->map_size_col);
  my_putstr("\nTetriminos :  ");
  my_put_nbr(game->tetriminos);
  my_putchar('\n');
  debug_tetriminos(game);
  my_putstr("Press any key to start Tetris\n");
}
