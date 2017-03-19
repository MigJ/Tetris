/*
** main.c for tetris in /home/detroy_j/Documents/delivery/tetris
** 
** Made by detroy_j
** Login   <jean-baptiste.detroyes@epitech.eu@epitech.net>
** 
** Started on  Mon Feb 20 14:56:18 2017 detroy_j
** Last update Fri Mar 17 15:15:29 2017 Joubert Miguel
*/

#include <unistd.h>
#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include "window.h"
#include "my.h"
#include "options.h"

int		game(t_options *opts, char **piece)
{
  t_window	win;
  t_game	game;

  game = init_game(game, opts, piece);
  win = init_window(win, opts);
  window(opts, piece, win, game);
  endwin();
  return (0);
}

int		main(int ac, char **av)
{
  t_options	*opts;
  char		**piece;

  piece = malloc(sizeof(char *) * 6);
  piece[0] = strdup("   *   ");
  piece[1] = strdup("  ***  ");
  piece[2] = strdup(" ***** ");
  piece[3] = strdup("*******");
  piece[4] = NULL;
  /*piece[0] = strdup("***");
    piece[1] = strdup("***");
    piece[2] = strdup("***");
    piece[3] = strdup("***");*/
  // piece[4] = strdup("");
  //piece[0] = strdup("****************************");
  //piece[1] = NULL;
  //piece = rotate(piece);
  /*  int i = 0;
      while (piece[i])
      {
      write(1, piece[i], strlen(piece[i]));
      write(1, "\n", 1);
      i++;
      }*/
  load();
  opts = init_options();
  get_arguments(opts, ac, av);
  if (opts->debug == 1)
    show_debug(opts);
  check_error_key(opts);
  game(opts, piece);
  return (free(piece), free(opts), 0);
}
