/*
** open.c for tetris in /home/detroy_j/Documents/delivery/tetris/srcs/tetriminos
** 
** Made by detroy_j
** Login   <jean-baptiste.detroyes@epitech.eu@epitech.net>
** 
** Started on  Wed Feb 22 18:36:20 2017 detroy_j
** Last update Fri Mar  3 20:04:49 2017 detroy_j
*/

#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include "tetriminos.h"
#include "my.h"

void	set_pointer(t_game *game, t_tetrimino *t, int fd)
{
  t->next = game->first;
  t->prev = NULL;
  if (game->first)
    game->first->prev = t;
  else
    game->last = t;
  game->first = t;
  game->tetriminos++;
  close(fd);
}

int	open_directory(t_game *game)
{
  DIR   *dir;
  struct dirent *dp;
  char  *path;
  int	fd;

  if ((dir = opendir("tetriminos")) == NULL)
    exit(84);
  while ((dp = readdir(dir)) != NULL)
    {
      if (dp->d_name[0] == '.' && dp->d_name[1] == '.' && dp->d_name[1] != '\0')
	continue;
      if (dp->d_name[0] == '.' && dp->d_name[1] != '\0')
	continue;
      if (!is_valid_extension(dp->d_name))
	continue;
      path = strcat_path(dp->d_name);
      if (!is_valid_file(path))
	continue;
      if ((fd = open(path, O_RDONLY)) < 0)
	continue;
      load_file(game, dp->d_name, fd);
      free(path);
    }
  return (0);
}
