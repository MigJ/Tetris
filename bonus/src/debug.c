/*
** debug.c for tetris in /home/detroy_j/Documents/delivery/tetris
** 
** Made by detroy_j
** Login   <jean-baptiste.detroyes@epitech.eu@epitech.net>
** 
** Started on  Mon Feb 20 18:15:33 2017 detroy_j
** Last update Fri Mar 17 14:47:22 2017 Joubert Miguel
*/

#include <stdio.h>
#include <unistd.h>
#include "options.h"

void	show_debug(t_options *opts)
{
  printf("*** DEBUG MODE ***\n");
  printf("Key Left : %c\nKey Right : %c\n", opts->k_left, opts->k_right);
  printf("Key Top : %c\nKey Drop : %c\n", opts->k_top, opts->k_drop);
  printf("Key Quit : %c\nKey Pause : %c\n", opts->k_quit, opts->k_pause);
  (opts->without_next == 0) ? printf("Next : No\n") : printf("Next : Yes\n");
  printf("Level : %d\nSize : %d*%d\n", opts->level,
	 opts->map_size_row, opts->map_size_col);
  printf("Press any key to start Tetris\n");
  sleep(2);
}
