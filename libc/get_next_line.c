/*

** get_next_line.c for libc in /home/le-mai_s/librairie/librairie_C/libc

**

** Made by sebastien le-maire

** Login   <le-mai_s@epitech.net>

**

** Started on  Mon Aug 10 10:33:58 2015 sebastien le-maire

** Last update Mon Oct 19 16:13:27 2015 sebastien le-maire

*/



#include <stdlib.h>


#include <string.h>
#include "rt_libc.h"


char		*get_next_line(FILE *file)

{

  char		*line;

  unsigned int	size;

  int		c;

  char		tmp[2];



  if (!(line = malloc(sizeof(char) * 1)))

    return (NULL);

  line[0] = '\0';

  size = 2;

  tmp[1] = '\0';

  while (((c = getc(file)) != EOF) && c != '\n')

    {

      if (!(line = realloc(line, sizeof(char) * size)))

	return (NULL);

      tmp[0] = c;

      line = strcat(line, tmp);

      ++size;

    }

  return (line);

}