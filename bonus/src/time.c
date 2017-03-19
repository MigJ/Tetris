/*
** time.c for  in /home/joubert/delivery/PSU_2016_tetris
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Fri Mar  3 19:24:20 2017 Joubert Miguel
** Last update Fri Mar 17 15:18:59 2017 Joubert Miguel
*/

#include <time.h>
#include "my.h"
#include "my_time.h"

int		timer()
{
  static int    i;
  static time_t old_time;
  time_t        new_time;
  static int    my_old_time;
  int           my_new_time;

  if (i == 0)
    {
      old_time = time(NULL);
      i++;
      return (my_old_time);
    }
  else
    {
      new_time = time(NULL);
      my_new_time = my_old_time + (new_time - old_time);
      old_time = new_time;
      my_old_time = my_new_time;
    }
  return (my_new_time);

}

t_my_time	convert_time(int nb)
{
  t_my_time     digits;

  digits.minuts = nb / 60;
  digits.seconds = nb % 60;
  return (digits);
}
