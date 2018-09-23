/*
** damier.c for raytracer in /home/le-mai_s/recode/TP/raytracer1/Raytracer/mlx
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Tue Oct 20 14:45:06 2015 sebastien le-maire
** Last update Tue Oct 20 14:45:21 2015 sebastien le-maire
*/

#include "raytracer_mlx.h"

int		damier(double x, double y, t_bool damier_on)
{
  unsigned int	damier[2];

  if (damier_on == TRUE)
    {
      damier[X] = (unsigned int)x % 100;
      damier[Y] = (unsigned int)y % 100;
      return (((damier[X] > 50 && damier[Y] > 50) ||
	       (damier[X] < 50 && damier[Y] < 50)) ? 1 : 0);
    }
  return (1);
}
