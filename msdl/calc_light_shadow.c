/*
** calc_light_shadow.c for raytracer in /home/le-mai_s/recode/TP/raytracer1/Raytracer/mlx
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Mon Sep 28 11:06:19 2015 sebastien le-maire
** Last update Mon Oct  5 16:37:46 2015 sebastien le-maire
*/

#include <stdlib.h>
#include "raytracer_mlx.h"

void		calc_inter(double (*inter)[3], t_objs *obj_inter,
			   t_eyes *eyes)
{
  double	pos[3];
  double	vector[3];

  fill_tab3d(&pos, eyes->pos[X] - obj_inter->pos[X],
  	     eyes->pos[Y] - obj_inter->pos[Y],
  	     eyes->pos[Z] - obj_inter->pos[Z]);
  fill_tab3d(&vector, eyes->vec[X], eyes->vec[Y], eyes->vec[Z]);
  rotate(&(obj_inter->rot), &pos, TRUE);
  rotate(&(obj_inter->rot), &vector, TRUE);
  fill_tab3d(inter, pos[X] + eyes->k * vector[X],
  	     pos[Y] + eyes->k * vector[Y],
  	     pos[Z] + eyes->k * vector[Z]);
}

void		calc_light(double (*light_vec)[3], double (*inter)[3],
			   t_spot *spot, t_objs *obj_inter)
{
  double	tmp[3];

  fill_tab3d(&tmp, spot->pos[X] - obj_inter->pos[X],
	     spot->pos[Y] - obj_inter->pos[Y],
	     spot->pos[Z] - obj_inter->pos[Z]);
  rotate(&(obj_inter->rot), &tmp, TRUE);
  fill_tab3d(light_vec, tmp[X] - (*inter)[X],
   	     tmp[Y] - (*inter)[Y],
   	     tmp[Z] - (*inter)[Z]);
}
