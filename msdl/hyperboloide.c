/*
** hyperboloide.c for  in /home/vergez_a/MUL_2014_rtracer/mlx
**
** Made by Luc VERGEZ
** Login   <vergez_a@epitech.net>
**
** Started on  Mon Oct 12 15:07:14 2015 Luc VERGEZ
** Last update Mon Oct 19 15:28:40 2015 sebastien le-maire
*/

#include "raytracer_mlx.h"
#include <math.h>

double          hyperboloide(t_objs *o, double (*pos)[3],
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
  fill_tab3d(&eq, HYPER_A(v[X], v[Y], v[Z], o->param),
             HYPER_B(p[X] * v[X], p[Y] * v[Y], p[Z] * v[Z], o->param),
             HYPER_C(p[X], p[Y], p[Z], o->param));
  if ((tmp_k[0] = eq_trinome(eq[X], eq[Y], eq[Z], k)) != k)
    {
      init_tmp_eyes(&eyes_tmp, pos, vec, tmp_k[0]);
      tmp_k[1] = eq_back_trinome(eq[X], eq[Y], eq[Z]);
      return ((limits_objs(o, &eyes_tmp, tmp_k[1])) ? eyes_tmp.k : k);
    }
  return (k);
}

void            calc_norm_hyper(double (*norm)[3], double (*inter)[3])
{
  double	mod;

  fill_tab3d(norm, (*inter)[X], (*inter)[Y], (*inter)[Z] * CTE);
  mod = NORM((*norm)[X], (*norm)[Y], (*norm)[Z]);
  fill_tab3d(norm, (*norm)[X] / mod, (*norm)[Y] / mod, (*norm)[Z] / mod);
}

double          calc_cos_hyper(double (*inter)[3], double (*light)[3])
{
  double	mod;
  double	norm[3];

  calc_norm_para(&norm, inter);
  mod = NORM((*light)[X], (*light)[Y], (*light)[Z]);
  fill_tab3d(light, (*light)[X] / mod, (*light)[Y] / mod, (*light)[Z] / mod);
  return ((norm[X] * (*light)[X]) + (norm[Y] * (*light)[Y]) +
	  (norm[Z] * (*light)[Z]));
}
