/*
** panel.c for  in /home/joubert/delivery/PSU_2016_tetris
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Fri Mar  3 19:25:39 2017 Joubert Miguel
** Last update Fri Mar 17 15:37:31 2017 Joubert Miguel
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"
#include "my_time.h"

char		*text_to_string(char *path, int length)
{
  int           fd;
  char          *txt;

  txt = my_memset(length);
  fd = open(path, O_RDONLY);
  read(fd, txt, length - 1);
  txt[length - 1] = 0;
  close(fd);
  return (txt);
}

char		*nb_to_ascii(int nb)
{
  char          **numbers;

  if ((numbers = malloc(sizeof(char *) * 11)) == NULL)
    return (NULL);
  numbers[0] = text_to_string("ressources/0", 48);
  numbers[1] = text_to_string("ressources/1", 48);
  numbers[2] = text_to_string("ressources/2", 44);
  numbers[3] = text_to_string("ressources/3", 44);
  numbers[4] = text_to_string("ressources/4", 44);
  numbers[5] = text_to_string("ressources/5", 44);
  numbers[6] = text_to_string("ressources/6", 44);
  numbers[7] = text_to_string("ressources/7", 44);
  numbers[8] = text_to_string("ressources/8", 44);
  numbers[9] = text_to_string("ressources/9", 44);
  numbers[10] = text_to_string("ressources/10", 52);
  return (numbers[nb]);
}

void		show_panel(WINDOW *panel, int score_count, int color)
{
  char          *score;
  char          *score_nb;
  char          *digital_watch;
  t_my_time     digits;

  verify_term_size();
  digital_watch = text_to_string("ressources/clock", 570);
  score = text_to_string("ressources/score", 230);
  digits = convert_time(timer());
  score_nb = nb_to_ascii(score_count);
  wclear(panel);
  wattron(panel, COLOR_PAIR(color));
  mvwprintw(panel, 15, 0, "%s", digital_watch);
  (digits.seconds < 10) ? mvwprintw(panel, 26, 22, "0%d", digits.seconds)
    : mvwprintw(panel, 26, 22, "%d", digits.seconds);
  (digits.minuts  < 10) ? mvwprintw(panel, 26, 18, "0%d", digits.minuts)
    : mvwprintw(panel, 26, 18, "%d", digits.minuts);
  mvwprintw(panel, 8, 0, "%s", score_nb);
  mvwprintw(panel, 1, 0, "%s", score);
  wattron(panel, COLOR_PAIR(color));
  box(panel, 0,0);
  free(score);
  free(score_nb);
  free(digital_watch);
}
