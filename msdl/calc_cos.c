/*
** calc_cos.c for raytracer in /home/le-mai_s/recode/TP/raytracer1/Raytracer/mlx
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Mon Sep 28 11:15:09 2015 sebastien le-maire
** Last update Thu Oct  8 15:46:58 2015 sebastien le-maire
*/

#include <math.h>
#include "raytracer_mlx.h"

double		calc_cos_sphere(double (*inter)[3], double (*light)[3])
{
  double	mod;
  double	norm[3];

  calc_norm_sphere(&norm, inter);
  mod = NORM((*light)[X], (*light)[Y], (*light)[Z]);
  fill_tab3d(light, (*light)[X] / mod, (*light)[Y] / mod, (*light)[Z] / mod);
  return ((norm[X] * (*light)[X]) + (norm[Y] * (*light)[Y]) +
	  (norm[Z] * (*light)[Z]));
}

double		calc_cos_plane(double (*inter)[3], double (*light)[3])
{
  double	mod;
  double	norm[3];

  calc_norm_plane(&norm, inter);
  mod = NORM((*light)[X], (*light)[Y], (*light)[Z]);
  (*light)[Z] /= mod;
  return ((norm[Z] * (*light)[Z]));
}

double		calc_cos_cylinder(double (*inter)[3], double (*light)[3])
{
  double	mod;
  double	norm[3];

  calc_norm_cylinder(&norm, inter);
  mod = NORM((*light)[X], (*light)[Y], (*light)[Z]);
  fill_tab3d(light, (*light)[X] / mod, (*light)[Y] / mod, (*light)[Z] / mod);
  return ((norm[X] * (*light)[X]) + (norm[Y] * (*light)[Y]));
}

double		calc_cos_cone(double (*inter)[3], double (*light)[3])
{
  double	mod;
  double	norm[3];

  calc_norm_cone(&norm, inter);
  mod = NORM((*light)[X], (*light)[Y], (*light)[Z]);
  fill_tab3d(light, (*light)[X] / mod, (*light)[Y] / mod, (*light)[Z] / mod);
  return ((norm[X] * (*light)[X]) + (norm[Y] * (*light)[Y]) +
	  (norm[Z] * (*light)[Z]));
}
