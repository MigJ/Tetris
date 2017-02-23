/*
** tetriminos.h for tetris in /home/detroy_j/Documents/delivery/tetris/include
** 
** Made by detroy_j
** Login   <jean-baptiste.detroyes@epitech.eu@epitech.net>
** 
** Started on  Tue Feb 21 16:37:41 2017 detroy_j
** Last update Thu Feb 23 14:55:43 2017 detroy_j
*/

#ifndef _TETRIMINOS_
# define _TETRIMINOS_

typedef struct s_tetrimino
{
  short	valid;
  char	*name;
  int	color;
  int	row;
  int	col;
  char	**shape;
  struct s_tetrimino	*next;
  struct s_tetrimino	*prev;
}	t_tetrimino;

typedef struct s_game
{
  t_tetrimino	*first;
  t_tetrimino	*last;
}	t_game;

int     order(t_game *g);
int     open_directory(t_game *game);
int     load_file(t_game *game, char *name, char *path);
char    *strcat_path(char *name);
int     is_valid_extension(char *name);
int     is_valid_file(char *name);
int     is_number(const char *str);

# endif
