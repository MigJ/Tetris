/*
** options_get_keys_bis.c for tetris in /home/detroy_j/Documents/delivery/tetris
** 
** Made by detroy_j
** Login   <jean-baptiste.detroyes@epitech.eu@epitech.net>
** 
** Started on  Mon Feb 20 18:10:03 2017 detroy_j
** Last update Fri Mar  3 13:17:07 2017 detroy_j
*/

#include <stdlib.h>
#include "options.h"
#include "my.h"

void	set_key_quit(t_options *opts, char *value)
{
  if (opts->k_defined[4] == 1)
    show_help(opts, 84);
  if (opts->k_quit != NULL)
    free(opts->k_quit);
  if (value[0] == 27)
    {
      if ((opts->k_quit = malloc(sizeof(char) * my_strlen(value) + 1)) == NULL)
	exit(84);
      opts->k_quit[my_strlen(value)] = '\0';
      my_strcat(opts->k_quit, "^E");
      value++;
      my_strcat(opts->k_quit, value);
    }
  else
    opts->k_quit = my_strdup(value);
  opts->k_defined[4] = 1;
}

void	set_key_pause(t_options *opts, char *value)
{
  if (opts->k_defined[5] == 1)
    show_help(opts, 84);
  if (opts->k_pause != NULL)
    free(opts->k_pause);
  if (value[0] == 27)
    {
      if ((opts->k_pause = malloc(sizeof(char) * my_strlen(value) + 1)) == NULL)
	exit(84);
      opts->k_pause[my_strlen(value)] = '\0';
      my_strcat(opts->k_pause, "^E");
      value++;
      my_strcat(opts->k_pause, value);
    }
  else
    opts->k_pause = my_strdup(value);
  opts->k_defined[5] = 1;
}
