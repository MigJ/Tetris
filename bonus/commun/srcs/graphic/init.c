/*
** init_game.c for  in /home/joubert/delivery/PSU_2016_tetris
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Mon Mar  6 18:11:56 2017 Joubert Miguel
** Last update Wed Mar  8 15:02:13 2017 Joubert Miguel
*/

#include "my.h"

void		verify_term_size()
{
  int		bol;

  bol = 0;
  while (COLS < 239 || LINES < 65)
    {
      clear();
      mvprintw(1, 1, "%s\n", "Please set full screen !");
      refresh();
      bol = 1;
    }
  if (bol == 1)
    {
      clear();
      refresh();
    }
}

t_window	init_window(t_window win, t_options *opts)
{
  verify_term_size();
  win.w = initscr();
  win.panel = newwin(50, 50, 5, 10);
  win.ground = newwin(opts->map_size_col, opts->map_size_row, 5, COLS / 2 - 22);
  keypad(stdscr, TRUE);
  start_color();
  init_colors();
  box(win.ground, 0, 0);
  wrefresh(win.ground);
  return (win);
}

t_game		init_game(t_game game, t_options *opts, char **piece)
{
  game.act.color = 7;
  game.act.drop = game.act.score_count = game.act.key = game.act.new = 0;
  game.co.y = -my_strlen_d_char(piece);
  game.co.x = (opts->map_size_row - count_colums(piece))/ 2;
  return (game);
}
