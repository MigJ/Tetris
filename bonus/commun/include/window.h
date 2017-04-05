/*
** window.h for  in /home/joubert/delivery/PSU_2016_tetris
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Fri Mar  3 19:39:46 2017 Joubert Miguel
** Last update Fri Mar  3 19:40:48 2017 Joubert Miguel
*/

#ifndef _WINDOW_H_
# define _WINDOW_H_

typedef struct s_window
{
  WINDOW        *w;
  WINDOW        *ground;
  WINDOW        *panel;
}t_window;

#endif /* WINDOW_H_ */
