/*
** my_strcat.c for libc in /home/le-mai_s/librairie/librairie_C/libc
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Mon Aug 10 10:31:52 2015 sebastien le-maire
** Last update Wed Oct 14 13:26:56 2015 sebastien le-maire
*/

#include "rt_libc.h"

char		*my_strcat(char *dest, const char *src)
{
  unsigned int	i;
  unsigned int	j;

  i = 0;
  j = my_strlen(dest);
  while (src[i])
    {
      dest[j] = src[i];
      ++i;
      ++j;
    }
  dest[j] = '\0';
  return (dest);
}
