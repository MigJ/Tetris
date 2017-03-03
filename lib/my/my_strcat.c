/*
** my_strcat.c for emacs in /home/detroy_j/delivery/lib
** 
** Made by jean-baptiste detroyes
** Login   <detroy_j@epitech.net>
** 
** Started on  Tue Oct 11 10:55:34 2016 jean-baptiste detroyes
** Last update Fri Mar  3 13:09:52 2017 detroy_j
*/

#include <stdlib.h>
#include <string.h>

size_t	my_strlen(const char *s);

char	*my_strcat(char *dest, const char *src)
{
  char	*curr;

  curr = dest;
  while (*curr)
    ++curr;
  while (*src)
    *(curr++) = *(src++);
  *(curr) = *(src);
  return (dest);
}
