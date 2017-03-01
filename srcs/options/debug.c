/*
** debug.c for tetris in /home/detroy_j/Documents/delivery/tetris
** 
** Made by detroy_j
** Login   <jean-baptiste.detroyes@epitech.eu@epitech.net>
** 
** Started on  Mon Feb 20 18:15:33 2017 detroy_j
** Last update Wed Mar  1 18:25:38 2017 detroy_j
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

static void	debug_tetriminos(t_game *game)
{
  t_tetrimino   *now;
  int   i;

  i = 0;
  now = game->first;
  while (now != NULL)
    {
      if (now->valid == 0)
	printf("Tetriminos : Name %s : Error\n", now->name);
      else
	{
	  printf("Tetriminos : Name %s : Size %d*%d : Color %d :\n", now->name, now->col, now->row, now->color);
	  while (i < now->row)
	    printf("%s\n", now->shape[i++]);
	}
      i = 0;
      now = now->next;
    }
}

void    show_debug(t_game *game, t_options *opts)
{
  printf("*** DEBUG MODE ***\n");
  printf("Key Left : %s\nKey Right : %s\n", get_key_name(opts->k_left), get_key_name(opts->k_right));
  printf("Key Turn : %s\nKey Drop : %s\n", get_key_name(opts->k_turn), get_key_name(opts->k_drop));
  printf("Key Quit : %s\nKey Pause : %s\n", get_key_name(opts->k_quit), get_key_name(opts->k_pause));
  (opts->without_next == 0) ? printf("Next : Yes\n") : printf("Next : No\n");
  printf("Level : %d\nSize : %d*%d\n", opts->level, opts->map_size_row, opts->map_size_col);
  printf("Tetriminos : %d\n", game->tetriminos);
  debug_tetriminos(game);
  printf("Press any key to start Tetris\n");
}
