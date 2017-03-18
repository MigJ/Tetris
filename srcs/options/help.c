/*
** help.c for tetris in /home/detroy_j/Documents/delivery/tetris/srcs
** 
** Made by detroy_j
** Login   <jean-baptiste.detroyes@epitech.eu@epitech.net>
** 
** Started on  Mon Feb 20 19:28:19 2017 detroy_j
** Last update Wed Mar 15 18:27:40 2017 detroy_j
*/

#include <stdlib.h>
#include <stdio.h>
#include "options.h"
#include "my.h"

void	show_help(t_options *opts, int i)
{
  my_putstr("Usage:   ");
  my_putstr(opts->bin_name);
  my_putstr(" [options]\nOptions:\n");
  my_putstr("   --help\t\tDisplay this help\n");
  my_putstr("   -l --level={num}\tStart Tetris at level num (def: 1)\n");
  my_putstr("   -kl --key-left={K}\tMove the tetrimino");
  my_putstr(" LEFT using the K key (def: left arrow)\n");
  my_putstr("   -kr --key-right={K}\tMove the tetrimino");
  my_putstr(" RIGHT using the K key (def: right arrow)\n");
  my_putstr("   -kt --key-turn={K}\tTURN the tetrimino ");
  my_putstr("clockwise 90d using the K key (def: top arrow)\n");
  my_putstr("   -kd --key-drop={K}\tDROP the tetrimino ");
  my_putstr("using the K key (def: down arrow)\n");
  my_putstr("   -kq --key-quit={K}\tQUIT the game ");
  my_putstr("using the K key (def: 'Q' key)\n");
  my_putstr("   -kp --key-pause={K}\tPAUSE/RESTART the ");
  my_putstr("game using the K key (def: space bar)\n");
  my_putstr("   --map-size={row,col}\tSet the numbers of ");
  my_putstr("rows and columns of the map (def: 20,10)\n");
  my_putstr("   -w --without-next\tHide next tetrimino (def: false)\n");
  my_putstr("   -d --debug\t\tDebug mode (def: false)\n");
  exit(i);
}
