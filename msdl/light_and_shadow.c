/*
** light_and_shadow.c for raytracer in /home/le-mai_s/recode/TP/raytracer1/Raytracer/mlx
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Mon Sep 21 14:52:42 2015 sebastien le-maire
** Last update Thu Oct 22 16:58:35 2015 sebastien le-maire
*/

#include <stdlib.h>
#include "raytracer_mlx.h"

#include <stdio.h>

double		shadow(t_class_objs *objs, t_objs *obj_inter,
		       double (*pos_spot)[3], double (*inter)[3])
{
  t_objs	*tmp;
  double	shade_inter[3];
  double	light_v[3];
  double	k;
  double	cte;

  cte = 1.0;
  tmp = objs->objs;
  fill_tab3d(&shade_inter, (*inter)[X], (*inter)[Y], (*inter)[Z]);
  move_real_pos(&shade_inter, obj_inter);
  fill_tab3d(&light_v, (*pos_spot)[X] - shade_inter[X],
	     (*pos_spot)[Y] - shade_inter[Y],
   	     (*pos_spot)[Z] - shade_inter[Z]);
  while (tmp)
    {
      if (tmp != obj_inter)
	{
	  k = objs->calc_objs[tmp->obj](tmp, &shade_inter, &light_v, 10);
	  if (k > 0.0000 && k < 1.0000)
	    cte *= tmp->refraction;
	}
      tmp = tmp->next;
    }
  return (cte);
}

void		light_and_shine(t_eyes *eyes, t_objs *obj_inter,
				t_spot *spot, double cos)
{
  unsigned int	rgb_eyes[3];
  unsigned int	rgb_obj[3];
  unsigned int	rgb_spot[3];

  separate_rgb(&rgb_eyes, eyes->color, eyes->endian);
  separate_rgb(&rgb_obj, obj_inter->color[0], eyes->endian);
  separate_rgb(&rgb_spot, spot->color, eyes->endian);
  rgb_eyes[R] += cos * (rgb_obj[R] + (rgb_spot[R] * obj_inter->shine));
  rgb_eyes[G] += cos * (rgb_obj[G] + (rgb_spot[G] * obj_inter->shine));
  rgb_eyes[B] += cos * (rgb_obj[B] + (rgb_spot[B] * obj_inter->shine));
  rgb_eyes[R] *= eyes->cte_trans;
  rgb_eyes[G] *= eyes->cte_trans;
  rgb_eyes[B] *= eyes->cte_trans;
  eyes->color = fusion_rgb(&rgb_eyes, eyes->endian);
}

void		light_and_shine_damier(t_eyes *eyes, t_objs *obj_inter,
				       t_spot *spot, double cos)
{
  unsigned int	rgb_eyes[3];
  unsigned int	rgb_obj[3];
  unsigned int	rgb_spot[3];

  separate_rgb(&rgb_eyes, eyes->color, eyes->endian);
  separate_rgb(&rgb_obj, obj_inter->color[1], eyes->endian);
  separate_rgb(&rgb_spot, spot->color, eyes->endian);
  rgb_eyes[R] += (cos * (rgb_obj[R] + (rgb_spot[R] * obj_inter->shine)));
  rgb_eyes[G] += (cos * (rgb_obj[G] + (rgb_spot[G] * obj_inter->shine)));
  rgb_eyes[B] += (cos * (rgb_obj[B] + (rgb_spot[B] * obj_inter->shine)));
  rgb_eyes[R] *= eyes->cte_trans;
  rgb_eyes[G] *= eyes->cte_trans;
  rgb_eyes[B] *= eyes->cte_trans;
  eyes->color = fusion_rgb(&rgb_eyes, eyes->endian);
}

void		light_and_shadow(t_eyes *eyes, t_class_objs *objs,
				 t_objs *obj_inter)
{
  double        light_v[3];
  t_spot	*spot;
  double	inter[3];
  double	cos;

  spot = objs->spot;
  calc_inter(&inter, obj_inter, eyes);
  while (spot)
    {
      if ((eyes->cte_trans = shadow(objs, obj_inter, &spot->pos, &inter)))
      	{
	  calc_light(&light_v, &inter, spot, obj_inter);
	  if ((cos = objs->calc_cos[obj_inter->obj](&inter, &light_v)) > 0.0)
	    {
	      if (obj_inter->obj != PLANE ||
		  damier(inter[X], inter[Y], obj_inter->text_pro))
		light_and_shine(eyes, obj_inter, spot, cos);
	      else
		light_and_shine_damier(eyes, obj_inter, spot, cos);
	    }
	}
      spot = spot->next;
    }
}
