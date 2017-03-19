/*
** load.h for  in /home/joubert/delivery/PSU_2016_tetris_ncurses
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Fri Mar 17 15:22:15 2017 Joubert Miguel
** Last update Fri Mar 17 15:23:09 2017 Joubert Miguel
*/

#ifndef _LOAD_H_
# define _LOAD_H_

typedef struct s_load
{
  WINDOW        *load;
  char          *stock;
  char          *bar;
  char          *wallpaper;
  int           fd;
  int           i;
}t_load;

#endif /* LOAD_H_ */
