/*
** misc.c for tetris in /home/detroy_j/Documents/delivery/tetris/srcs/tetriminos
** 
** Made by detroy_j
** Login   <jean-baptiste.detroyes@epitech.eu@epitech.net>
** 
** Started on  Wed Feb 22 17:53:51 2017 detroy_j
** Last update Wed Feb 22 18:48:05 2017 detroy_j
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h> 
#include <string.h>
#include "my.h"

int     is_valid_extension(char *name)
{
  while (*name != '\0')
    {
      if (*name == '.')
	break;
      name++;
    }
  if (my_strcmp(name, ".tetrimino") == 0)
    return (1);
  return (0);
}

int	is_valid_file(char *name)
{
  struct stat   filestat;

  if (stat(name, &filestat) < 0)
    return (0);
  if (S_ISREG(filestat.st_mode))
    return (1);
  return (0);
}

char	*strcat_path(char *name)
{
  char *path;
  int   i;
  int   j;
  int	len;

  j = 0;
  i = 11;
  if ((path = malloc(sizeof(char) * (my_strlen(name) + 12))) == NULL)
    exit(84);
  len = my_strlen(name);
  my_strcpy(path, "tetriminos/");
  while (j < len)
    {
      path[i] = name[j];
      i++;
      j++;
    }
  path[i] = '\0';
  return (path);
}
