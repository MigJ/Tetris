/*
** menu.c for  in /home/joubert/delivery/PSU_2016_tetris
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Mon Feb 20 18:43:45 2017 Joubert Miguel
** Last update Fri Mar 17 15:32:24 2017 Joubert Miguel
*/

#include <ncurses.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "load.h"
#include "my.h"

static t_load		init_load(t_load ld)
{
  ld.i = 0;
  ld.stock = my_memset(30);
  ld.bar = my_memset(100);
  ld.wallpaper = my_memset((2000 * 1000));
  initscr();
  start_color();
  init_color(COLOR_BLACK, 0, 0, 0);
  curs_set(0);
  ld.fd = open("ressources/load", O_RDONLY);
  init_pair(1, COLOR_RED, COLOR_RED);
  assume_default_colors(COLOR_RED, COLOR_BLACK);
  ld.load = newwin(2, 45, 50, 30);
  wrefresh(ld.load);
  noecho();
  read(ld.fd, ld.wallpaper, (2000 * 1000));
  ld.wallpaper[1616] = 0;
  return (ld);
}

static t_load		first_load(t_load ld)
{
  ld = init_load(ld);
  while (ld.i < 22)
    {
      ld.bar[ld.i] = ' ';
      ld.bar[ld.i + 1] = 0;
      wattron(ld.load, COLOR_PAIR(1));
      sprintf(ld.stock, "%s", ld.bar);
      mvprintw(5, 1, "%s", ld.wallpaper);
      refresh();
      mvwprintw(ld.load, 0, ld.i++,"%s", ld.stock);
      wrefresh(ld.load);
      usleep(50000);
    }
  free(ld.bar);
  clear();
  delwin(ld.load);
  refresh();
  return (ld);
}

void			load()
{
  t_load		ld;

  ld = first_load(ld);
  mvprintw(5, 1, "%s", ld.wallpaper);
  mvprintw(45, 45, "Press ENTER to continue\n");
  while (getch() != '\n')
    {
      refresh();
      mvprintw(5, 1, "%s", ld.wallpaper);
      mvprintw(45, 45, "Press ENTER to continue\n");
    }
  free(ld.wallpaper);
  free(ld.stock);
  clear();
  refresh();
  endwin();
}
