/*
** options_get.c for tetris in /home/detroy_j/Documents/delivery/tetris
** 
** Made by detroy_j
** Login   <jean-baptiste.detroyes@epitech.eu@epitech.net>
** 
** Started on  Mon Feb 20 18:02:37 2017 detroy_j
** Last update Sat Mar 18 14:47:32 2017 detroy_j
*/

#include <stdlib.h>
#include <string.h>
#include "my.h"
#include "options.h"

static int	check_double_option(char *name, char *value)
{
  int		failed;

  failed = 0;
  (my_strcmp(value, SOPT_LEVEL) == 0) ? failed = 1 : 0;
  (my_strcmp(value, SOPT_KEY_RIGHT) == 0) ? failed = 1 : 0;
  (my_strcmp(value, SOPT_KEY_LEFT) == 0) ? failed = 1 : 0;
  (my_strcmp(value, SOPT_KEY_TURN) == 0) ? failed = 1 : 0;
  (my_strcmp(value, SOPT_KEY_DROP) == 0) ? failed = 1 : 0;
  (my_strcmp(value, SOPT_KEY_QUIT) == 0) ? failed = 1 : 0;
  (my_strcmp(value, SOPT_KEY_PAUSE) == 0) ? failed = 1 : 0;
  (my_strcmp(value, SOPT_WITHOUT) == 0) ? failed = 1 : 0;
  (my_strncmp(value, OPT_LEVEL, 7) == 0) ? failed = 1 : 0;
  (my_strncmp(value, OPT_KEY_LEFT, 10) == 0) ? failed = 1 : 0;
  (my_strncmp(value, OPT_KEY_RIGHT, 11) == 0) ? failed = 1 : 0;
  (my_strncmp(value, OPT_KEY_TURN, 10) == 0) ? failed = 1 : 0;
  (my_strncmp(value, OPT_KEY_DROP, 10) == 0) ? failed = 1 : 0;
  (my_strncmp(value, OPT_KEY_QUIT, 10) == 0) ? failed = 1 : 0;
  (my_strncmp(value, OPT_KEY_PAUSE, 11) == 0) ? failed = 1 : 0;
  (my_strncmp(value, OPT_WITHOUT, 14) == 0) ? failed = 1 : 0;
  (my_strncmp(value, OPT_SIZE, 10) == 0) ? failed = 1 : 0;
  if (failed != 0)
    return (0);
  return (1);
}

void	get_option(t_options *opts, char *name, char *value)
{
  if (value[0] == '\0')
    show_help(opts, 84);
  if (!check_double_option(name, value))
    show_help(opts, 84);
  if (my_strcmp(name, OPT_LEVEL) == 0)
    set_start_level(opts, value);
  else if (my_strcmp(name, OPT_KEY_LEFT) == 0)
    set_key_left(opts, value);
  else if (my_strcmp(name, OPT_KEY_RIGHT) == 0)
    set_key_right(opts, value);
  else if (my_strcmp(name, OPT_KEY_TURN) == 0)
    set_key_turn(opts, value);
  else if (my_strcmp(name, OPT_KEY_DROP) == 0)
    set_key_drop(opts, value);
  else if (my_strcmp(name, OPT_KEY_QUIT) == 0)
    set_key_quit(opts, value);
  else if (my_strcmp(name, OPT_KEY_PAUSE) == 0)
    set_key_pause(opts, value);
  else if (my_strcmp(name, OPT_SIZE) == 0)
    set_map_size(opts, value);
  else
    show_help(opts, 84);
}

void	get_short_option(t_options *opts, char *name, char *value)
{
  if (value[0] == '\0')
    show_help(opts, 84);
  if (!check_double_option(name, value))
    show_help(opts, 84);
  if (my_strcmp(name, SOPT_LEVEL) == 0)
    set_start_level(opts, value);
  else if (my_strcmp(name, SOPT_KEY_LEFT) == 0)
    set_key_left(opts, value);
  else if (my_strcmp(name, SOPT_KEY_RIGHT) == 0)
    set_key_right(opts, value);
  else if (my_strcmp(name, SOPT_KEY_TURN) == 0)
    set_key_turn(opts, value);
  else if (my_strcmp(name, SOPT_KEY_DROP) == 0)
    set_key_drop(opts, value);
  else if (my_strcmp(name, SOPT_KEY_QUIT) == 0)
    set_key_quit(opts, value);
  else if (my_strcmp(name, SOPT_KEY_PAUSE) == 0)
    set_key_pause(opts, value);
  else
    show_help(opts, 84);
}

int	get_static_arguments(t_options *opts, int i, char **av)
{
  if (my_strcmp(av[i], OPT_WITHOUT) == 0
      || my_strcmp(av[i], SOPT_WITHOUT) == 0)
    {
      opts->without_next = 1;
      return (1);
    }
  else if (my_strcmp(av[i], OPT_DEBUG) == 0
	   || my_strcmp(av[i], SOPT_DEBUG) == 0)
    {
      opts->debug = 1;
      return (1);
    }
  else if (my_strcmp(av[i], "--help") == 0)
    show_help(opts, 0);
  return (0);
}

void	get_arguments(t_options *opts, int ac, char **av)
{
  int   i;
  char  *str;

  i = 1;
  while (i < ac)
    {
      if (get_static_arguments(opts, i, av))
	{
	  i++;
	  continue;
	}
      if (!have_equal(av[i]))
	{
	  (i + 1 == ac) ? show_help(opts, 84) : 0;
	  get_short_option(opts, av[i], av[i + 1]);
	  i += 2;
	  continue;
	}
      str = my_strsep(&av[i], "=");
      get_option(opts, str, av[i]);
      i++;
    }
}
