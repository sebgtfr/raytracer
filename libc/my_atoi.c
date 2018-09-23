/*
** my_atoi.c for libc in /home/le-mai_s/librairie/librairie_C/libc
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Mon Aug 10 10:31:04 2015 sebastien le-maire
** Last update Tue Oct 20 13:05:26 2015 sebastien le-maire
*/

#include <limits.h>
#include "rt_libc.h"

int		my_atoi_base(const char *nbr, const char *base)
{
  int		s;
  int		nb;
  unsigned int	pos;
  unsigned int	size_base;
  unsigned int	b;

  s = (nbr[0] == '-') ? -1 : 1;
  pos = (s == -1) ? 1 : 0;
  nb = 0;
  size_base = my_strlen(base);
  while (nbr[pos])
    {
      b = 0;
      while (b < size_base && base[b] != nbr[pos])
	++b;
      if (base[b] == nbr[pos])
	nb = (nb * size_base) + b;
      else
	return (0);
      ++pos;
    }
  return (nb * s);
}

int		my_atoi(const char *str)
{
  int		nb;
  int		s;
  unsigned int	pos;

  s = (str[0] == '-') ? -1 : 1;
  pos = (s == -1) ? 1 : 0;
  nb = 0;
  while (str[pos] && IS_NUM(str[pos]))
    {
      nb = (nb * 10) + CHAR_TO_INT(str[pos]);
      ++pos;
    }
  return (nb * s);
}
