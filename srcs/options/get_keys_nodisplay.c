/*
** get_keys_nodisplay.c for tetris in /home/detroy_j/Documents/delivery/PSU_2016_tetris/srcs/options
** 
** Made by detroy_j
** Login   <jean-baptiste.detroyes@epitech.eu@epitech.net>
** 
** Started on  Wed Mar  1 13:31:27 2017 detroy_j
** Last update Fri Mar  3 10:32:39 2017 detroy_j
*/

#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include <term.h>
#include "options.h"
#include "my.h"

char	*get_no_display_key(char *str)
{
  int	len;
  char	*result;

  //my_putstr(str);
  if (str == 0)
    return (NULL);
  if (str[0] == 27)
    {
      len = my_strlen(str);
      if ((result = malloc(sizeof(char) * len + 2)) == NULL)
	exit(84);
      len = 1;
      result[0] = '^';
      result[1] = 'E';
      while (str[len] != '\0')
	{
	  result[len + 1] = str[len];
	  len ++;
	}
      result[len + 1] = '\0';
    }
    return (result);
}

