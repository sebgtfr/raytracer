/*
** calc_norm.c for raytracer in /home/le-mai_s/recode/TP/raytracer1/Raytracer/mlx
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Thu Oct  1 11:04:37 2015 sebastien le-maire
** Last update Sun Oct 18 16:32:07 2015 sebastien le-maire
*/

#include <math.h>
#include "raytracer_mlx.h"

void		calc_norm_sphere(double (*norm)[3], double (*inter)[3])
{
  double	mod;

  mod = NORM((*inter)[X], (*inter)[Y], (*inter)[Z]);
  fill_tab3d(norm, (*inter)[X] / mod, (*inter)[Y] / mod, (*inter)[Z] / mod);
}

void		calc_norm_cylinder(double (*norm)[3], double (*inter)[3])
{
  double	mod;

  mod = sqrt(pow((*inter)[X], 2) + pow((*inter)[Y], 2));
  fill_tab3d(norm, (*inter)[X] / mod, (*inter)[Y] / mod, 0);
}

void		calc_norm_cone(double (*norm)[3], double (*inter)[3])
{
  double	mod;

  fill_tab3d(norm, (*inter)[X], (*inter)[Y], (*inter)[Z] * CTE);
  mod = NORM((*norm)[X], (*norm)[Y], (*norm)[Z]);
  fill_tab3d(norm, (*norm)[X] / mod, (*norm)[Y] / mod, (*norm)[Z] / mod);
}

void		calc_norm_plane(double (*norm)[3],
				__attribute__((unused))double (*inter)[3])
{
  fill_tab3d(norm, 0, 0, 1);
}
