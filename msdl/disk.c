/*
** disk.c for raytracer in /home/le-mai_s/recode/TP/raytracer1/Raytracer/mlx
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Thu Oct 15 12:49:04 2015 sebastien le-maire
** Last update Thu Oct 15 16:00:14 2015 sebastien le-maire
*/

#include <math.h>
#include "raytracer_mlx.h"

double	        disk(t_objs *o, double (*pos)[3],
		     double (*vec)[3], double k)
{
  double	p[3];
  double	v[3];
  double	new_k;
  double	inter[3];
  t_eyes	eyes_tmp;

  fill_tab3d(&p, (*pos)[X] - o->pos[X], (*pos)[Y] - o->pos[Y],
	     (*pos)[Z] - o->pos[Z]);
  fill_tab3d(&v, (*vec)[X], (*vec)[Y], (*vec)[Z]);
  rotate(&o->rot, &p, TRUE);
  rotate(&o->rot, &v, TRUE);
  if (v[Z] < 0.0001 && v[Z] > -0.0001)
    return (k);
  new_k = PLANE_Z(p[Z], v[Z]);
  if (new_k >= 0.0001 && new_k < k)
    {
      init_tmp_eyes(&eyes_tmp, pos, vec, new_k);
      calc_inter(&inter, o, &eyes_tmp);
      return ((pow(inter[X], 2) + pow(inter[Y], 2)) < pow(o->param, 2) ?
	      (limit_disk(o, &inter)) ? new_k : k : k);
    }
  return (k);
}
