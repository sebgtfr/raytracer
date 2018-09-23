/*
** paraboloide.c for raytracer in /home/le-mai_s/recode/TP/raytracer1/Raytracer/mlx
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Thu Oct  8 15:24:47 2015 sebastien le-maire
** Last update Thu Oct 15 11:09:00 2015 sebastien le-maire
*/

#include <math.h>
#include "raytracer_mlx.h"

double		paraboloide(t_objs *o, double (*pos)[3],
			    double (*vec)[3], double k)
{
  double	eq[3];
  double	p[3];
  double	v[3];
  double	tmp_k[2];
  t_eyes	eyes_tmp;

  fill_tab3d(&p, (*pos)[X] - o->pos[X], (*pos)[Y] - o->pos[Y],
	     (*pos)[Z] - o->pos[Z]);
  fill_tab3d(&v, (*vec)[X], (*vec)[Y], (*vec)[Z]);
  rotate(&o->rot, &p, TRUE);
  rotate(&o->rot, &v, TRUE);
  fill_tab3d(&eq, PARA_A(v[X], v[Y]),
	     PARA_B(p[X] * v[X], p[Y] * v[Y], v[Z], o->param),
	     PARA_C(p[X], p[Y], p[Z], o->param));
  if ((tmp_k[0] = eq_trinome(eq[X], eq[Y], eq[Z], k)) != k)
    {
      init_tmp_eyes(&eyes_tmp, pos, vec, tmp_k[0]);
      tmp_k[1] = eq_back_trinome(eq[X], eq[Y], eq[Z]);
      return ((limits_objs(o, &eyes_tmp, tmp_k[1])) ? eyes_tmp.k : k);
    }
  return (k);
}

void		calc_norm_para(double (*norm)[3], double (*inter)[3])
{
  double	mod;

  mod = NORM((*inter)[X], (*inter)[Y], -0.1);
  fill_tab3d(norm, (*inter)[X] / mod, (*inter)[Y] / mod, CTE / mod);
}

double		calc_cos_para(double (*inter)[3], double (*light)[3])
{
  double	mod;
  double	norm[3];

  calc_norm_para(&norm, inter);
  mod = NORM((*light)[X], (*light)[Y], (*light)[Z]);
  fill_tab3d(light, (*light)[X] / mod, (*light)[Y] / mod, (*light)[Z] / mod);
  return ((norm[X] * (*light)[X]) + (norm[Y] * (*light)[Y]) +
	  (norm[Z] * (*light)[Z]));
}
