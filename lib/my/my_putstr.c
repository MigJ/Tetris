/*
** my_putstr.c for emacs in /home/detroy_j/delivery/CPool_Day04
** 
** Made by jean-baptiste detroyes
** Login   <detroy_j@epitech.net>
** 
** Started on  Thu Oct  6 09:32:44 2016 jean-baptiste detroyes
** Last update Wed Jan 11 20:32:26 2017 detroy_j
*/

#include <unistd.h>
#include <string.h>

size_t  my_strlen(const char *s);

int	my_putstr(const char *str)
{
  write(1, str, my_strlen(str));
  return (0);
}
