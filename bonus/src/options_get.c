/*
** options_get.c for tetris in /home/detroy_j/Documents/delivery/tetris
** 
** Made by detroy_j
** Login   <jean-baptiste.detroyes@epitech.eu@epitech.net>
** 
** Started on  Mon Feb 20 18:02:37 2017 detroy_j
** Last update Mon Feb 20 18:06:31 2017 detroy_j
*/

#include <stdlib.h>
#include <string.h>
#include "my.h"
#include "options.h"

void	get_option(t_options *opts, char *name, char *value)
{
  if (my_strcmp(name, "-l") == 0)
    set_start_level(opts, value);
  else if (my_strcmp(name, "-key-left") == 0)
    set_key_left(opts, value);
  else if (my_strcmp(name, "-key-right") == 0)
    set_key_right(opts, value);
  else if (my_strcmp(name, "-key-top") == 0)
    set_key_top(opts, value);
  else if (my_strcmp(name, "-key-drop") == 0)
    set_key_drop(opts, value);
  else if (my_strcmp(name, "-key-quit") == 0)
    set_key_quit(opts, value);
  else if (my_strcmp(name, "-key-pause") == 0)
    set_key_pause(opts, value);
  else if (my_strcmp(name, "-map-size") == 0)
    set_map_size(opts, value);
}

void	get_arguments(t_options *opts, int ac, char **av)
{
  int   i;
  char  *str;

  i = 1;
  while (i < ac)
    {
      if (my_strcmp(av[i], "-without-next") == 0)
	{
	  opts->without_next = 1;
	  i++;
	  continue;
	}
      else if (my_strcmp(av[i], "-debug") == 0)
	{
	  opts->debug = 1;
	  i++;
	  continue;
	}
      if (!have_equal(av[i]))
	exit(84);
      str = my_strsep(&av[i], "=");
      get_option(opts, str, av[i]);
      i++;
    }
}
