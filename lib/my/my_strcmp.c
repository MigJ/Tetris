/*
** my_strcmp.c for emacs in /home/detroy_j/delivery/CPool_Day06
** 
** Made by jean-baptiste detroyes
** Login   <detroy_j@epitech.net>
** 
** Started on  Mon Oct 10 16:50:48 2016 jean-baptiste detroyes
** Last update Wed Jan 11 20:28:02 2017 detroy_j
*/

#include <string.h>

size_t  my_strlen(const char *s);

int	my_strcmp(const char *s1, const char *s2)
{
  size_t   i;

  if (my_strlen(s1) < my_strlen(s2))
    return (-1);
  if (my_strlen(s1) > my_strlen(s2))
    return (1);
  i = 0;
  while (s1[i] && s2[i] && s1[i] == s2[i])
    i++;
  return (s1[i] - s2[i]);
}
