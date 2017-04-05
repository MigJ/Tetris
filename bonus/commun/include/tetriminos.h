/*
** tetriminos.h for tetris in /home/detroy_j/Documents/delivery/tetris/include
** 
** Made by detroy_j
** Login   <jean-baptiste.detroyes@epitech.eu@epitech.net>
** 
** Started on  Tue Feb 21 16:37:41 2017 detroy_j
** Last update Sun Mar 19 15:19:05 2017 detroy_j
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
  char	**d_shape;
  struct s_tetrimino	*next;
  struct s_tetrimino	*prev;
}	t_tetrimino;

typedef struct s_g
{
  int	tetriminos;
  t_tetrimino	*first;
  t_tetrimino	*last;
}	t_g;

/*
** Load
*/
void    open_directory(t_g *game);
int     load_file(t_g *game, char *name, int fd);
void    set_pointer(t_g *game, t_tetrimino *t, int fd);
int     check_line(t_tetrimino *t, char *str);

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
int     order(t_g *g);

/*
** Free
*/
void    my_free_tetriminos(t_g *game);

# endif
