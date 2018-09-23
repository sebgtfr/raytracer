/*
** eyes.c for raytracer in /home/le-mai_s/recode/TP/raytracer1/Raytracer/mlx
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Thu Sep 10 17:04:02 2015 sebastien le-maire
** Last update Wed Oct 21 11:25:58 2015 sebastien le-maire
*/

#include <float.h>
#include "raytracer_mlx.h"

void		init_tmp_eyes(t_eyes *eyes, double (*pos)[3],
			      double (*vec)[3], double k)
{
  fill_tab3d(&eyes->pos, (*pos)[X], (*pos)[Y], (*pos)[Z]);
  fill_tab3d(&eyes->vec, (*vec)[X], (*vec)[Y], (*vec)[Z]);
  eyes->k = k;
}

void		fill_tab3d(double (*tab3d)[3], double x,
			   double y, double z)
{
  (*tab3d)[X] = x;
  (*tab3d)[Y] = y;
  (*tab3d)[Z] = z;
}

void		init_eyes(t_eyes *eyes, double x, double y, double z)
{
  eyes->pos[X] = x;
  eyes->pos[Y] = y;
  eyes->pos[Z] = z;
  eyes->rot[X] = 0;
  eyes->rot[Y] = 0;
  eyes->rot[Z] = 0;
}

void	        set_eyes(t_eyes *eyes)
{
  eyes->k = DBL_MAX;
  eyes->color = BLACK;
}
