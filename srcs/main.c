/*
** main.c for tetris in /home/detroy_j/Documents/delivery/tetris
** 
** Made by detroy_j
** Login   <jean-baptiste.detroyes@epitech.eu@epitech.net>
** 
** Started on  Mon Feb 20 14:56:18 2017 detroy_j
** Last update Fri Mar  3 13:44:12 2017 detroy_j
*/

#include <unistd.h>
#include <term.h>
#include <curses.h>
#include <string.h>
#include <stdlib.h>
#include "my.h"
#include "options.h"
#include "tetriminos.h"

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
  t_game	*game;
  t_options	*opts;
  int	error;

  if (setupterm(get_term_variable(env), 1, &error) != OK)
    return (84);
  opts = init_options();
  if ((opts->bin_name = malloc(sizeof(char) * my_strlen(av[0]) + 1)) == NULL)
    exit(84);
  my_strcpy(opts->bin_name, av[0]);
  get_arguments(opts, ac, av);
  game = malloc(sizeof(*game));
  game->first = game->last = NULL;
  game->tetriminos = 0;
  open_directory(game);
  order(game);
  if (opts->debug == 1)
    show_debug(game, opts);
  check_error_key(opts);
  my_free_options(opts);
  my_free_tetriminos(game);
  return (0);
}
