/*
** refraction.c for raytracer in /home/le-mai_s/recode/TP/raytracer1/Raytracer/mlx
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Tue Oct 20 18:39:55 2015 sebastien le-maire
** Last update Wed Oct 21 22:01:31 2015 sebastien le-maire
*/

#include <math.h>
#include "raytracer_mlx.h"

void		calc_refraction_vector(double (*refraction_v)[3],
				       double (*norm)[3],
				       double (*vision)[3],
				       double c)
{
  fill_tab3d(refraction_v, REFRACTION((*norm)[X], (*vision)[X], c),
  	     REFRACTION((*norm)[Y], (*vision)[Y], c),
  	     REFRACTION((*norm)[Z], (*vision)[Z], c));
}

void		color_refraction(t_eyes *eyes, t_objs *obj,
				 t_eyes *new_eyes)
{
  unsigned int	rgb_eyes[3];
  unsigned int	rgb_obj[3];
  unsigned int	rgb_reflect[3];

  separate_rgb(&rgb_eyes, eyes->color, eyes->endian);
  separate_rgb(&rgb_obj, obj->color[0], eyes->endian);
  separate_rgb(&rgb_reflect, new_eyes->color, eyes->endian);
  rgb_eyes[R] += (rgb_reflect[R] * obj->refraction +
  		  rgb_obj[R] * (1 - obj->refraction ));
  rgb_eyes[G] += (rgb_reflect[G] * obj->refraction +
  		  rgb_obj[G] * (1 - obj->refraction));
  rgb_eyes[B] += (rgb_reflect[B] * obj->refraction +
  		  rgb_obj[B] * (1 - obj->refraction));
  eyes->color = fusion_rgb(&rgb_eyes, eyes->endian);
}

void		refraction(t_eyes *eyes, t_class_objs *objs,
			   t_objs *obj_inter, t_eyes *new)
{
  t_objs	*obj;

  set_eyes(new);
  new->endian = eyes->endian;
  if ((obj = inter_objs(new, objs, obj_inter)))
    {
      light_and_shadow(new, objs, obj);
      color_refraction(eyes, obj_inter, new);
    }
}
