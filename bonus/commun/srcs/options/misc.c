/*
** misc.c for tetris in /home/detroy_j/Documents/delivery/tetris
** 
** Made by detroy_j
** Login   <jean-baptiste.detroyes@epitech.eu@epitech.net>
** 
** Started on  Mon Feb 20 17:53:37 2017 detroy_j
** Last update Fri Mar  3 20:08:08 2017 detroy_j
*/

#include <string.h>
#include <unistd.h>
#include "my.h"

void	my_putstr_error(const char *s)
{
  size_t        i;

  i = my_strlen(s);
  write(2, s, i);
}

int	is_number(const char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < '0' || str[i] > '9')
	return (0);
      i++;
    }
  return (1);
}

int	have_comma(const char *str)
{
  int   i;
  int   comma;

  i = comma = 0;
  while (str[i] != '\0')
    {
      if (str[i] == ',')
	comma++;
      i++;
    }
  return ((comma == 1) ? 1 : 0);
}

int	have_equal(const char *str)
{
  int   i;
  int   equal;

  i = equal = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '=')
	equal++;
      i++;
    }
  return ((equal == 1) ? 1 : 0);
}
