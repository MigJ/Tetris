/*
** memset.c for  in /home/joubert/delivery/PSU_2016_tetris_ncurses
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Fri Mar 17 14:27:58 2017 Joubert Miguel
** Last update Fri Mar 17 15:16:06 2017 Joubert Miguel
*/

#include <stdlib.h>
#include "../include/my.h"

char		*my_memset(int size)
{
  char		*str;
  int		i;

  if ((str = malloc(sizeof(char) * size)) == NULL)
    return (NULL);
  i = -1;
  while (++i < size)
    str[i] = 0;
  return (str);
}
