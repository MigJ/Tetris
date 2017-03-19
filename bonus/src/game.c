/*
** game.c for  in /home/joubert/delivery/PSU_2016_tetris
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Wed Mar  8 14:12:33 2017 Joubert Miguel
** Last update Fri Mar 17 15:47:36 2017 Joubert Miguel
*/

#include <unistd.h>
#include "my.h"
#include "options.h"

void		window(t_options *opts, char **piece, t_window win, t_game game)
{
  while (44)
    {
      show_panel(win.panel, game.act.score_count, game.act.color);
      box(win.ground, 0, 0);
      game = key_pressed(opts, win, game, &piece);
      if (game.act.key == opts->k_quit)
	break;
      else if (game.act.key == opts->k_pause)
	break;
      cbreak();
      nodelay(win.w, TRUE);
      disp_piece(piece, game.co, win.ground, game.act.color);
      if (game.act.new == 1)
	{
	  if (game.co.y < 0)
	    break;
	  game = create_new_piece(opts, win, game, piece);
	}
      wrefresh(win.panel);
      wrefresh(win.ground);
      game.act.key = getch();
      while (getch() != -1);
      if (game.act.drop == 0) usleep(250000 - (10000 * opts->level));
      else usleep(50000 - (10000 * opts->level));
    }
}

t_game		is_touched_down(t_options *opts, t_window win,
				t_game game, char ***piece)
{
  if (game.co.y != COL_WALL_DOWN && COL_DOWN != 1)
    clear_piece(*piece, game.co.y++, game.co.x, win.ground);
  else
    {
      game.act.new = 1;
      game.act.drop = 0;
    }
  return (game);
}

t_game		key_pressed(t_options *opts, t_window win,
			    t_game game, char ***piece)
{
  if (game.act.key == opts->k_left)
    game.co.x = (game.co.x != COL_WALL_LEFT && COL_LEFT != 1)
      ? clear_piece(*piece, game.co.y, game.co.x, win.ground), game.co.x - 1
      : game.co.x;
  else if (game.act.key == opts->k_right)
    game.co.x = (game.co.x != COL_WALL_RIGHT && COL_RIGHT != 1)
      ? clear_piece(*piece, game.co.y, game.co.x, win.ground), game.co.x + 1
      : game.co.x;
  else if (game.act.key == opts->k_drop)
    game.act.drop = 1;
  else if (game.act.key == opts->k_quit)
    return (game);
  else if (game.act.key == opts->k_pause)
    {
      while ((game.act.key = getch()) != opts->k_pause);
      game.act.key = 0;
    }
  else if (game.act.key == opts->k_top
	   && COL_ROTATE != 1 && COL_WALL_ROTATE != 1)
    {
      clear_piece(*piece, game.co.y, game.co.x, win.ground);
      *piece = rotate(*piece);
    }
  return (is_touched_down(opts, win, game, piece));
}

t_game		create_new_piece(t_options *opts, t_window win,
				 t_game game, char **piece)
{
  game.act.color = (game.act.color == 7) ? 1 : game.act.color + 1;
  game.co.y = -my_strlen_d_char(piece);
  game.co.x = (opts->map_size_row - count_colums(piece))/ 2;
  game.act.new = 0;
  if (detect_full_line(win.ground,
		       opts->map_size_col,
		       opts->map_size_row) != -1)
    {
      game.act.score_count++, opts->level++;
      clear_line(detect_full_line(win.ground,
				  opts->map_size_col,
				  opts->map_size_row),
		 win.ground, opts->map_size_row);
    }
  return (game);
}
