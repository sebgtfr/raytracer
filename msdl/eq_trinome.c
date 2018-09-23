/*
** eq_trinome.c for raytracer in /home/le-mai_s/recode/TP/raytracer1/Raytracer/mlx
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Tue Oct  6 14:00:27 2015 sebastien le-maire
** Last update Tue Oct  6 14:01:05 2015 sebastien le-maire
*/

#include <math.h>
#include "raytracer_mlx.h"

double		eq_trinome(double a, double b,
			   double c, double old_k)
{
  double	new_k;
  double	delta;
  double	x[2];

  if ((delta = DELTA(a, b, c)) < 0)
    new_k = old_k;
  else if (!delta)
    new_k = X0(a, b);
  else
    {
      x[0] = X1(a, b, delta);
      x[1] = X2(a, b, delta);
      new_k = (x[0] > 0 &&
	       ((x[1] > 0 && x[0] < x[1]) || (x[1] < 0))) ? x[0] : x[1];
    }
  return ((new_k > 0 && new_k < old_k) ? new_k : old_k);
}

double		eq_back_trinome(double a, double b, double c)
{
  double	new_k;
  double	delta;
  double	x[2];

  if ((delta = DELTA(a, b, c)) <= 0)
    return (-1);
  else
    {
      x[0] = X1(a, b, delta);
      x[1] = X2(a, b, delta);
      new_k = (x[0] > 0 &&
	       ((x[1] > 0 && x[0] < x[1]) || (x[1] < 0))) ? x[1] : x[0];
    }
  return ((new_k > 0) ? new_k : -1);
}
