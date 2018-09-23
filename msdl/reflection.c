/*
** reflection.c for raytracer in /home/le-mai_s/recode/TP/raytracer1/Raytracer/mlx
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Tue Oct 20 10:16:57 2015 sebastien le-maire
** Last update Wed Oct 21 22:02:06 2015 sebastien le-maire
*/

#include <math.h>
#include <stdlib.h>
#include "raytracer_mlx.h"

void		calc_vision(double (*vision)[3], double (*inter)[3],
			    double (*pos_eyes)[3])
{
  double	mod;

  fill_tab3d(vision, (*inter)[X] - (*pos_eyes)[X],
   	     (*inter)[Y] - (*pos_eyes)[Y],
   	     (*inter)[Z] - (*pos_eyes)[Z]);
  mod = NORM((*vision)[X], (*vision)[Y], (*vision)[Z]);
  fill_tab3d(vision, (*vision)[X] / mod, (*vision)[Y] / mod,
	     (*vision)[Z] / mod);
}

void		calc_reflection_vector(double (*reflection_v)[3],
				       double (*norm)[3],
				       double (*vision)[3],
				       double c)
{
  fill_tab3d(reflection_v, REFLECTION((*norm)[X], (*vision)[X], c),
	     REFLECTION((*norm)[Y], (*vision)[Y], c),
	     REFLECTION((*norm)[Z], (*vision)[Z], c));
}

void		color_reflection(t_eyes *eyes, t_objs *obj,
				 t_eyes *new_eyes)
{
  unsigned int	rgb_eyes[3];
  unsigned int	rgb_obj[3];
  unsigned int	rgb_reflect[3];

  separate_rgb(&rgb_eyes, eyes->color, eyes->endian);
  separate_rgb(&rgb_obj, obj->color[0], eyes->endian);
  separate_rgb(&rgb_reflect, new_eyes->color, eyes->endian);
  rgb_eyes[R] += (rgb_reflect[R] * obj->reflection +
  		  rgb_obj[R] * (1 - obj->reflection ));
  rgb_eyes[G] += (rgb_reflect[G] * obj->reflection +
  		  rgb_obj[G] * (1 - obj->reflection));
  rgb_eyes[B] += (rgb_reflect[B] * obj->reflection +
  		  rgb_obj[B] * (1 - obj->reflection));
  eyes->color = fusion_rgb(&rgb_eyes, eyes->endian);
}

void		reflection(t_eyes *eyes, t_class_objs *objs,
			   t_objs *obj_inter, t_eyes *new)
{
  t_objs	*obj;

  set_eyes(new);
  new->endian = eyes->endian;
  if ((obj = inter_objs(new, objs, obj_inter)))
    {
      light_and_shadow(new, objs, obj);
      color_reflection(eyes, obj_inter, new);
    }
}
