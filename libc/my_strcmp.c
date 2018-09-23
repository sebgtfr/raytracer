/*
** my_strcmp.c for libc in /home/le-mai_s/librairie/librairie_C/libc
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Mon Aug 10 10:32:16 2015 sebastien le-maire
** Last update Tue Oct 20 13:06:38 2015 sebastien le-maire
*/

#include "rt_libc.h"

int		my_strncmp(const char *s1, const char *s2,
			   const unsigned int size)
{
  unsigned int	pos;

  pos = 0;
  while ((s1[pos] || s2[pos]) && (pos < size) && (s1[pos] == s2[pos]))
    ++pos;
  pos -= (pos == size) ? 1 : 0;
  return (s1[pos] - s2[pos]);
}

int		my_strcmp(const char *s1, const char *s2)
{
  unsigned int	pos;

  pos = 0;
  while ((s1[pos] || s2[pos]) && (s1[pos] == s2[pos]))
    ++pos;
  return (s1[pos] - s2[pos]);
}
