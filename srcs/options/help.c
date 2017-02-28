/*
** help.c for tetris in /home/detroy_j/Documents/delivery/tetris/srcs
** 
** Made by detroy_j
** Login   <jean-baptiste.detroyes@epitech.eu@epitech.net>
** 
** Started on  Mon Feb 20 19:28:19 2017 detroy_j
** Last update Tue Feb 28 18:18:03 2017 detroy_j
*/

#include <stdlib.h>
#include <stdio.h>
#include "options.h"

void	show_help(t_options *opts, int i)
{
  printf("Usage:   %s [options]\nOptions:\n", opts->bin_name);
  printf("   --help\t\tDisplay this help\n");
  printf("   -l --level={num}\tStart Tetris at level num (def: 1)\n");
  printf("   -kl --key-left={K}\tMove the tetrimino LEFT using the K key (def: left arrow)\n");
  printf("   -kr --key-right={K}\tMove the tetrimino RIGHT using the K key (def: right arrow)\n");
  printf("   -kt --key-turn={K}\tTURN the tetrimino clockwise 90d using the K key (def: top arrow)\n");
  printf("   -kd --key-drop={K}\tDROP the tetrimino using the K key (def: down arrow)\n");
  printf("   -kq --key-quit={K}\tQUIT the game using the K key (def: 'Q' key)\n");
  printf("   -kp --key-pause={K}\tPAUSE/RESTART the game using the K key (def: space bar)\n");
  printf("   --map-size={row,col}\tSet the numbers of rows and columns of the map (def: 20,10)\n");
  printf("   -w --without-next\tHide next tetrimino (def: false)\n");
  printf("   -d --debug\t\tDebug mode (def: false)\n");
  exit(i);
}
