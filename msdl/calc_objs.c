/*
** calc_objs.c for raytracer in /home/le-mai_s/recode/TP/raytracer1/Raytracer/mlx
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Thu Sep 10 19:33:14 2015 sebastien le-maire
** Last update Thu Oct 15 22:49:23 2015 sebastien le-maire
*/

#include <math.h>
#include "raytracer_mlx.h"

double	        plane(t_objs *o, double (*pos)[3],
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
      return ((limit_plane(o, &inter)) ? new_k : k);
    }
  return (k);
}

double		sphere(t_objs *s, double (*pos)[3],
		       double (*vec)[3], double k)
{
  double	eq[3];
  double	p[3];
  double	v[3];
  double	tmp_k[2];
  t_eyes	eyes_tmp;

  fill_tab3d(&p, (*pos)[X] - s->pos[X], (*pos)[Y] - s->pos[Y],
	     (*pos)[Z] - s->pos[Z]);
  fill_tab3d(&v, (*vec)[X], (*vec)[Y], (*vec)[Z]);
  rotate(&(s->rot), &p, TRUE);
  rotate(&(s->rot), &v, TRUE);
  fill_tab3d(&eq, SPHERE_A(v[X], v[Y], v[Z]),
	     SPHERE_B(p[X] * v[X], p[Y] * v[Y], p[Z] * v[Z]),
	     SPHERE_C(p[X], p[Y], p[Z], s->param));
  if ((tmp_k[0] = eq_trinome(eq[X], eq[Y], eq[Z], k)) != k)
    {
      init_tmp_eyes(&eyes_tmp, pos, vec, tmp_k[0]);
      tmp_k[1] = eq_back_trinome(eq[X], eq[Y], eq[Z]);
      return (((s->param * 2) > (double)(s->limit[MAX] - s->limit[MIN])) ?
	      ((limits_objs(s, &eyes_tmp, tmp_k[1])) ? eyes_tmp.k : k) : k);
    }
  return (k);
}

double		cylinder(t_objs *c, double (*pos)[3],
			 double (*vec)[3], double k)
{
  double	eq[3];
  double	p[3];
  double	v[3];
  double	tmp_k[2];
  t_eyes	eyes_tmp;

  fill_tab3d(&p, (*pos)[X] - c->pos[X], (*pos)[Y] - c->pos[Y],
	     (*pos)[Z] - c->pos[Z]);
  fill_tab3d(&v, (*vec)[X], (*vec)[Y], (*vec)[Z]);
  rotate(&(c->rot), &p, TRUE);
  rotate(&(c->rot), &v, TRUE);
  fill_tab3d(&eq, CYLINDER_A(v[X], v[Y]),
	     CYLINDER_B(p[X] * v[X], p[Y] * v[Y]),
	     CYLINDER_C(p[X], p[Y], c->param));
  if ((tmp_k[0] = eq_trinome(eq[X], eq[Y], eq[Z], k)) != k)
    {
      init_tmp_eyes(&eyes_tmp, pos, vec, tmp_k[0]);
      tmp_k[1] = eq_back_trinome(eq[X], eq[Y], eq[Z]);
      return ((limits_objs(c, &eyes_tmp, tmp_k[1])) ? eyes_tmp.k : k);
    }
  return (k);
}

double		cone(t_objs *c, double (*pos)[3],
		     double (*vec)[3], double k)
{
  double	eq[3];
  double	p[3];
  double	v[3];
  double	angle;
  double	tmp_k[2];
  t_eyes	eyes_tmp;

  angle = (c->param > 0 && (!(c->param % 90))) ? 1 : 90 - (c->param % 90);
  fill_tab3d(&p, (*pos)[X] - c->pos[X], (*pos)[Y] - c->pos[Y],
	     (*pos)[Z] - c->pos[Z]);
  fill_tab3d(&v, (*vec)[X], (*vec)[Y], (*vec)[Z]);
  rotate(&(c->rot), &p, TRUE);
  rotate(&(c->rot), &v, TRUE);
  fill_tab3d(&eq, CONE_A(v[X], v[Y], v[Z], tan(RAD(angle))),
	     CONE_B(p[X] * v[X], p[Y] * v[Y], p[Z] * v[Z], tan(RAD(angle))),
	     CONE_C(p[X], p[Y], p[Z], tan(RAD(angle))));
  if ((tmp_k[0] = eq_trinome(eq[X], eq[Y], eq[Z], k)) != k)
    {
      init_tmp_eyes(&eyes_tmp, pos, vec, tmp_k[0]);
      tmp_k[1] = eq_back_trinome(eq[X], eq[Y], eq[Z]);
      return ((limits_objs(c, &eyes_tmp, tmp_k[1])) ? eyes_tmp.k : k);
    }
  return (k);
}
