/*
** options_get_keys.c for tetris in /home/detroy_j/Documents/delivery/tetris
** 
** Made by detroy_j
** Login   <jean-baptiste.detroyes@epitech.eu@epitech.net>
** 
** Started on  Mon Feb 20 18:07:36 2017 detroy_j
** Last update Wed Mar  1 15:28:11 2017 detroy_j
*/

#include <stdlib.h>
#include <curses.h>
#include <term.h>
#include <stdio.h>
#include "options.h"

void	set_key_left(t_options *opts, char *value)
{
  /*nb = *value;
  if (nb == 0)
    exit(84);
    opts->k_left = nb;*/
  opts->k_left = value;
}

void	set_key_right(t_options *opts, char *value)
{
  /*int   nb;

  nb = *value;
  if (nb == 0)
    exit(84);*/
  opts->k_right = value;
}

void	set_key_drop(t_options *opts, char *value)
{
  /*int   nb;

  nb = *value;
  if (nb == 0)
  exit(84);*/
  opts->k_drop = value;
}

void	set_key_turn(t_options *opts, char *value)
{
  /*int   nb;

  nb = *value;
  if (nb == 0)
  exit(84);*/
  opts->k_turn = value;
}
