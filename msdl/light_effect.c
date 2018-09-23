/*
** light_effect.c for raytracer in /home/le-mai_s/recode/TP/raytracer1/Raytracer/mlx
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Thu Oct  1 10:26:40 2015 sebastien le-maire
** Last update Wed Oct 21 22:03:43 2015 sebastien le-maire
*/

#include "raytracer_mlx.h"

void		light_effect(t_eyes *eyes, t_class_objs *objs,
			     t_objs *obj_inter)
{
  double	norm[3];
  double	vision[3];
  double	c;
  t_eyes	new;

  calc_inter(&new.pos, obj_inter, eyes);
  objs->calc_norm[obj_inter->obj](&norm, &new.pos);
  move_real_pos(&(new.pos), obj_inter);
  calc_vision(&vision, &new.pos, &(eyes->pos));
  c = norm[X] * vision[X] + norm[Y] * vision[Y] + norm[Z] * vision[Z];
  if (obj_inter->reflection)
    {
      calc_reflection_vector(&new.vec, &norm, &vision, c);
      reflection(eyes, objs, obj_inter, &new);
    }
  if (obj_inter->refraction)
    {
      calc_refraction_vector(&new.vec, &norm, &vision, c);
      refraction(eyes, objs, obj_inter, &new);
    }
}
