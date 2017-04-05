/*
** main.c for tetris in /home/detroy_j/Documents/delivery/tetris
** 
** Made by detroy_j
** Login   <jean-baptiste.detroyes@epitech.eu@epitech.net>
** 
** Started on  Mon Feb 20 14:56:18 2017 detroy_j
** Last update Sun Mar 19 16:40:40 2017 detroy_j
*/

#include <unistd.h>
#include <term.h>
#include <curses.h>
#include <string.h>
#include <stdlib.h>
#include "window.h"
#include "my.h"
#include "options.h"
#include "tetriminos.h"

int		game(t_options *opts, char **piece)
{
  t_window      win;
  t_game        game;

  game = init_game(game, opts, piece);
  win = init_window(win, opts);
  window(opts, piece, win, game);
  endwin();
  return (0);
}

char	*get_term_variable(char **env)
{
  char	*result;
  int	i;

  i = 0;
  while (env[i] != NULL)
    {
      while ((result = my_strsep(&env[i], "=")) != NULL)
	{
	  if (my_strcmp(result, "TERM") == 0)
	    return (env[i]);
	}
      i++;
    }
  return (NULL);
}

int	main(int ac, char **av, char **env)
{
  t_g	*g;
  t_options	*opts;
  int	error;
  char          **piece;

  piece = malloc(sizeof(char *) * 6);
  piece[0] = strdup("******");
  piece[1] = strdup("******");
  piece[2] = strdup("******");
  piece[3] = strdup("******");
  piece[4] = NULL;
  if (setupterm("xterm-256color", 1, &error) != OK)
    return (84);
  opts = init_options();
  if ((opts->bin_name = malloc(sizeof(char) * my_strlen(av[0]) + 1)) == NULL)
    exit(84);
  my_strcpy(opts->bin_name, av[0]);
  get_arguments(opts, ac, av);
  g = malloc(sizeof(*g));
  g->first = g->last = NULL;
  g->tetriminos = 0;
  open_directory(g);
  order(g);
  check_error_key(opts);
  if (opts->debug == 1)
    show_debug(g, opts);
  getchar();
  load();
  game(opts, piece);
  my_free_options(opts);
  my_free_tetriminos(g);
  return (0);
}
