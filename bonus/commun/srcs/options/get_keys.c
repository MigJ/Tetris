/*
** options_get_keys.c for tetris in /home/detroy_j/Documents/delivery/tetris
** 
** Made by detroy_j
** Login   <jean-baptiste.detroyes@epitech.eu@epitech.net>
** 
** Started on  Mon Feb 20 18:07:36 2017 detroy_j
** Last update Sun Mar 19 15:56:40 2017 detroy_j
*/

#include <stdlib.h>
#include <curses.h>
#include <term.h>
#include <stdio.h>
#include "options.h"
#include "my.h"

void	set_key_left(t_options *opts, char *value)
{
  if (opts->k_defined[0] == 1)
    show_help(opts, 84);
  if (opts->k_left != NULL)
    free(opts->k_left);
  if (value[0] == 27)
    {
      if ((opts->k_left = malloc(sizeof(char) * my_strlen(value) + 1)) == NULL)
	exit(84);
      opts->k_left[my_strlen(value)] = '\0';
      my_strcat(opts->k_left, "^E");
      value++;
      my_strcat(opts->k_left, value);
    }
  else
    opts->k_left = my_strdup(value);
  opts->k_defined[0] = 1;
}

void	set_key_right(t_options *opts, char *value)
{
  if (opts->k_defined[1] == 1)
    show_help(opts, 84);
  if (opts->k_right != NULL)
    free(opts->k_right);
  if (value[0] == 27)
    {
      if ((opts->k_right = malloc(sizeof(char) * my_strlen(value) + 1)) == NULL)
	exit(84);
      opts->k_right[my_strlen(value)] = '\0';
      my_strcat(opts->k_right, "^E");
      value++;
      my_strcat(opts->k_right, value);
    }
  else
    opts->k_right = my_strdup(value);
  opts->k_defined[1] = 1;
}

void	set_key_drop(t_options *opts, char *value)
{
  if (opts->k_defined[2] == 1)
    show_help(opts, 84);
  if (opts->k_drop != NULL)
    free(opts->k_drop);
  if (value[0] == 27)
    {
      if ((opts->k_drop = malloc(sizeof(char) * my_strlen(value) + 1)) == NULL)
	exit(84);
      opts->k_drop[my_strlen(value)] = '\0';
      my_strcat(opts->k_drop, "^E");
      value++;
      my_strcat(opts->k_drop, value);
    }
  else
    opts->k_drop = my_strdup(value);
  opts->k_defined[2] = 1;
}

void	set_key_turn(t_options *opts, char *value)
{
  if (opts->k_defined[3] == 1)
    show_help(opts, 84);
  if (opts->k_turn != NULL)
    free(opts->k_turn);
  if (value[0] == 27)
    {
      if ((opts->k_turn = malloc(sizeof(char) * my_strlen(value) + 1)) == NULL)
	exit(84);
      opts->k_turn[my_strlen(value)] = '\0';
      my_strcat(opts->k_turn, "^E");
      value++;
      my_strcat(opts->k_turn, value);
    }
  else
    opts->k_turn = my_strdup(value);
  opts->k_defined[3] = 1;
}
