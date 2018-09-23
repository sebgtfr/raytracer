/*
** my_strdup.c for libc in /home/le-mai_s/librairie/librairie_C/libc
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Mon Aug 10 10:32:42 2015 sebastien le-maire
** Last update Wed Oct 14 13:26:11 2015 sebastien le-maire
*/

#include <stdlib.h>
#include "rt_libc.h"

char		*my_strdup(const char *src)
{
  char		*dest;

  if (!(dest = newstr(my_strlen(src))))
    return (NULL);
  return (my_strcpy(dest, src));
}
