/*
** mem.c for rt_libc in /home/le-mai_s/rendu/Projet_Igraph_repository/MUL_2014_rtracer/libc
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Wed Oct 14 13:16:33 2015 sebastien le-maire
** Last update Wed Oct 14 13:17:13 2015 sebastien le-maire
*/

#include <stdlib.h>
#include "rt_libc.h"

void		*my_memset(void *mem, const unsigned int size)
{
  unsigned int	i;

  i = 0;
  while (i < size)
    ((char *)mem)[i++] = '\0';
  return (mem);
}

char		*newstr(const unsigned int size)
{
  char		*new;
  unsigned int	pos;

  if (!(new = malloc(sizeof(char) * (size + 1))))
    return (NULL);
  pos = 0;
  while (pos <= size)
    new[pos++] = '\0';
  return (new);
}
