/*
** tetriminos.h for tetris in /home/detroy_j/Documents/delivery/tetris/include
** 
** Made by detroy_j
** Login   <jean-baptiste.detroyes@epitech.eu@epitech.net>
** 
** Started on  Tue Feb 21 16:37:41 2017 detroy_j
** Last update Fri Mar  3 13:29:46 2017 detroy_j
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
  int	tetriminos;
  t_tetrimino	*first;
  t_tetrimino	*last;
}	t_game;

/*
** Load
*/
int     open_directory(t_game *game);
int     load_file(t_game *game, char *name, char *path);

/*
** Miscs
*/
int     is_valid_extension(char *name);
int     is_valid_file(char *name);
int     is_number(const char *str);
char    *strcat_path(char *name);

/*
** Tri
*/
int     order(t_game *g);

/*
** Free
*/
void    my_free_tetriminos(t_game *game);

# endif
