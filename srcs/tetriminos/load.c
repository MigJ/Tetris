/*
** load.c for tetris in /home/detroy_j/Documents/delivery/tetris/srcs/tetriminos
** 
** Made by detroy_j
** Login   <jean-baptiste.detroyes@epitech.eu@epitech.net>
** 
** Started on  Wed Feb 22 18:33:27 2017 detroy_j
** Last update Thu Mar  9 17:06:12 2017 detroy_j
*/

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include "tetriminos.h"
#include "my.h"

static void	read_file_config(t_tetrimino *tetri, char *str)
{
  char		*value;
  char		**add;
  int		i;

  i = 0;
  add = &str;
  while ((value = my_strsep(add, " ")) != NULL)
    {
      (i == 0) ? tetri->col = my_getnbr(value) : 0;
      (i == 1) ? tetri->row = my_getnbr(value) : 0;
      (i == 2) ? tetri->color = my_getnbr(value) : 0;
      i++;
    }
  if (i != 3)
    tetri->valid = 0;
  if (str != NULL)
    free(str);
}

static int	read_file_map(t_tetrimino *tetri, char *str, int i, int l)
{
  int		j;
  int		k;

  j = 0;
  k = my_strlen(str);
  if (k > tetri->col)
    {
      while (k >= tetri->col)
	{
	  if (str[k] == '*')
	    {
	      tetri->valid = 0;
	      return (0);
	    }
	  k--;
	}
    }
  while (str[j] != '\0' && j < tetri->col)
    {
      if (str[j] != '*' && str[j] != ' ')
	return (tetri->valid = 0);
      if (l <= j)
	l = j;
      tetri->shape[i][j] = str[j];
      j++;
    }
  while (j < tetri->col)
    tetri->shape[i][j++] = ' ';
  tetri->d_shape[i] = my_strdup(str);
  k = my_strlen(tetri->d_shape[i]) - 1;
  while (k > 0)
    {
      if (tetri->d_shape[i][k] == ' ')
	tetri->d_shape[i][k] = '\0';
      else if (tetri->d_shape[i][k] == '*')
	break;
      k--;
    }
  tetri->shape[i][j] = '\0';
  return (l);
}

static int	get_name(t_tetrimino *t, char *name)
{
  int	len;
  int	i;

  len = my_strlen(name);
  while (len > 0)
    {
      if (name[len] == '.')
	break;
      len--;
    }
  if ((t->name = malloc(sizeof(char) * (len + 1))) == NULL)
    exit(84);
  i = 0;
  while (i < len)
    {
      t->name[i] = name[i];
      i++;
    }
  t->name[i] = '\0';
  return (0);
}

static void	malloc_tetrimino(t_tetrimino *t, int fd)
{
  char	*str;
  int	i;

  i = 0;
  if ((str = get_next_line(fd)) != NULL)
    {
      read_file_config(t, str);
      (str != NULL) ? free(str) : 0;
    }
  if (t->row > 0 && t->col > 0)
    {
      if ((t->shape = malloc(sizeof(char *) * (t->row + 1))) == NULL)
	exit(84);
      if ((t->d_shape = malloc(sizeof(char *) * (t->row + 1))) == NULL)
	exit(84);
      while (i < t->row)
	{
	  if ((t->shape[i] = malloc(sizeof(char) * (t->col + 1))) == NULL)
	    exit(84);
	  if ((t->d_shape[i] = malloc(sizeof(char) * (t->col + 1))) == NULL)
	    exit(84);
	  i++;
	}
      t->shape[t->row] = t->d_shape[t->row] = NULL;
    }
}

int	load_file(t_game *game, char *name, int fd)
{
  t_tetrimino   *new;
  char  *str;
  int   i;
  int   j;
  int   l;

  if ((new = malloc(sizeof(*new))) == NULL)
    exit(84);
  get_name(new, name);
  new->valid = 1;
  new->col = new->row = new->color = -1;
  i = j = l = 0;
  malloc_tetrimino(new, fd);
  while ((str = get_next_line(fd)) != NULL && j < new->row)
    {
      l = read_file_map(new, str, i, l);
      i++;
      j++;
      free(str);
    }
  if (l + 1 < new->col || new->color == -1 || new->col == -1
      || new->row == -1 || new->color >= 1000)
    new->valid = 0;
  set_pointer(game, new, fd);
  return (0);
}
