/*
** game.h for  in /home/joubert/delivery/PSU_2016_tetris
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Mon Mar  6 16:25:52 2017 Joubert Miguel
** Last update Mon Mar  6 16:28:10 2017 Joubert Miguel
*/

#ifndef _GAME_H_
# define _GAME_H_

#include "collision.h"
#include "actions.h"

typedef struct s_game
{
  t_vector      co;
  t_params      act;
}t_game;

#endif /* _GAME_H_ */
