/*

** my_puterror.c for puterror in /home/le-mai_s/rendu/Projet_Igraph_repository/MUL_2014_rtv1/lib
**

** Made by sebastien le-maire

** Login   <le-mai_s@epitech.net>

**

** Started on  Wed Jul 29 12:00:45 2015 sebastien le-maire

** Last update Mon Oct 19 10:51:15 2015 sebastien le-maire

*/



#include <stdio.h>

#include "rt_libc.h"



int	my_strlen(const char *str)

{

  int	i;


  i = 0;


  while (str[i])

    ++i;

  return (i);

}



int	my_puterror(const char *str, const int err)

{

  (void)fprintf(stderr, "%s", str);

  return (err);

}
