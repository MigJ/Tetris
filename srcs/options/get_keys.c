/*
** options_get_keys.c for tetris in /home/detroy_j/Documents/delivery/tetris
** 
** Made by detroy_j
** Login   <jean-baptiste.detroyes@epitech.eu@epitech.net>
** 
** Started on  Mon Feb 20 18:07:36 2017 detroy_j
** Last update Tue Feb 28 18:44:00 2017 detroy_j
*/

#include <stdlib.h>
#include <curses.h>
#include <term.h>
#include <stdio.h>
#include "options.h"

void	set_key_left(t_options *opts, char *value)
{
  int   nb;

  if (tigetstr("smln") != 0)
    printf("tigetstr: %s\n", tigetstr("smln"));
  nb = *value;
  if (nb == 0)
    exit(84);
  opts->k_left = nb;
}

void	set_key_right(t_options *opts, char *value)
{
  int   nb;

  nb = *value;
  if (nb == 0)
    exit(84);
  opts->k_right = nb;
}

void	set_key_drop(t_options *opts, char *value)
{
  int   nb;

  nb = *value;
  if (nb == 0)
    exit(84);
  opts->k_drop = nb;
}

void	set_key_turn(t_options *opts, char *value)
{
  int   nb;

  nb = *value;
  if (nb == 0)
    exit(84);
  opts->k_turn = nb;
}
