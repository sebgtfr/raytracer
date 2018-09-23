/*
** color.c for raytracer in /home/le-mai_s/recode/TP/raytracer1/Raytracer/mlx
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Mon Sep 28 11:40:10 2015 sebastien le-maire
** Last update Mon Sep 28 14:34:44 2015 sebastien le-maire
*/

#include <stdlib.h>
#include "raytracer_mlx.h"

void		separate_rgb(unsigned int (*rgb)[3], unsigned int color,
			     const int endian)
{
  if (endian == LIT_ENDIAN)
    {
      (*rgb)[R] = GET_LE_RED(color);
      (*rgb)[G] = GET_LE_GREEN(color);
      (*rgb)[B] = GET_LE_BLUE(color);
    }
  else
    {
      (*rgb)[R] = GET_BE_RED(color);
      (*rgb)[G] = GET_BE_GREEN(color);
      (*rgb)[B] = GET_BE_BLUE(color);
    }
}

unsigned int	fusion_rgb(unsigned int (*rgb)[3], const int endian)
{
  unsigned int	i;

  i = 0;
  while (i < 3)
    {
      if ((*rgb)[i] > 0xFF)
	(*rgb)[i] = 0xFF;
      ++i;
    }
  return ((endian == LIT_ENDIAN) ? LE_RGB((*rgb)[R], (*rgb)[G], (*rgb)[B]) :
	  BE_RGB((*rgb)[R], (*rgb)[G], (*rgb)[B]));
}
