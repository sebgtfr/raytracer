/*
** rotate.c for graph in /home/le-mai_s/recode/TP/raytracer1/lib
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Thu Jul  2 09:44:19 2015 sebastien le-maire
** Last update Mon Sep 28 16:47:07 2015 sebastien le-maire
*/

#include "raytracer_mlx.h"

void		calc_matrix_pt(t_matrix *m, double (*pt)[3])
{
  double	p[3];

  p[X] = ((*pt)[X] * m->m[0][0] + (*pt)[Y] * m->m[0][1]
	  + (*pt)[Z] * m->m[0][2]);
  p[Y] = ((*pt)[X] * m->m[1][0] + (*pt)[Y] * m->m[1][1]
	  + (*pt)[Z] * m->m[1][2]);
  p[Z] = ((*pt)[X] * m->m[2][0] + (*pt)[Y] * m->m[2][1]
	  + (*pt)[Z] * m->m[2][2]);
  (*pt)[X] = p[X];
  (*pt)[Y] = p[Y];
  (*pt)[Z] = p[Z];
}

void		rotate(double (*angle)[3], double (*pt)[3], t_bool inversed)
{
  t_matrix	m;
  double	tmp_angle[3];

  init_matrix(&m);
  if (inversed == TRUE)
    fill_tab3d(&tmp_angle, -(*angle)[X], -(*angle)[Y], -(*angle)[Z]);
  else
    fill_tab3d(&tmp_angle, (*angle)[X], (*angle)[Y], (*angle)[Z]);
    rotate_x(&m, tmp_angle[X]);
    rotate_y(&m, tmp_angle[Y]);
    rotate_z(&m, tmp_angle[Z]);
  if (tmp_angle[X] || tmp_angle[Y] || tmp_angle[Z])
    calc_matrix_pt(&m, pt);
}
