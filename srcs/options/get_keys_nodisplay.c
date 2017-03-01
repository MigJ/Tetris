/*
** get_keys_nodisplay.c for tetris in /home/detroy_j/Documents/delivery/PSU_2016_tetris/srcs/options
** 
** Made by detroy_j
** Login   <jean-baptiste.detroyes@epitech.eu@epitech.net>
** 
** Started on  Wed Mar  1 13:31:27 2017 detroy_j
** Last update Wed Mar  1 18:12:16 2017 detroy_j
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
  
  if (str == 0)
    return (NULL);
  len = my_strlen(str);
  if ((result = malloc(sizeof(char) * len + 2)) == NULL)
    exit(84);
  
  if (my_strlen(str) > 2)
    {
      result[0] = '^';
      result[1] = 'E';
      result[2] = 'O';
      result[3] = str[2];
      result[4] = '\0';
    }
  else
    {
      result[0] = '^';
      result[1] = 'E';
      result[2] = str[1];
      result[3] = '\0';
    }
  return (result);
}

