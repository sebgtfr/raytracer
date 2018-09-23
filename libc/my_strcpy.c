/*
** my_strcpy.c for libc in /home/le-mai_s/librairie/librairie_C/libc
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Mon Aug 10 10:31:32 2015 sebastien le-maire
** Last update Wed Oct 14 13:24:22 2015 sebastien le-maire
*/

#include "rt_libc.h"

char	*strlcpy(char *dest, char *src, int size)
{
  int	i;

  i = 0;
  while ((dest[i] = src[i]) && i < size)
    i++;
  dest[size - 1] = '\0';
  return (dest);
}

char		*my_strncpy(char *dest, const char *src,
			    const unsigned int size)
{
  unsigned int	i;

  i = 0;
  while ((dest[i] = src[i]) && i < size)
    ++i;
  dest[i] = '\0';
  return (dest);
}

char		*my_strcpy(char *dest, const char *src)
{
  unsigned int	i;

  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      ++i;
    }
  dest[i] = '\0';
  return (dest);
}
