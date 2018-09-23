/*
** move_real_pos.c for raytracer in /home/le-mai_s/recode/TP/raytracer1/Raytracer/mlx
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Mon Oct  5 10:30:43 2015 sebastien le-maire
** Last update Mon Oct  5 10:43:04 2015 sebastien le-maire
*/

#include "raytracer_mlx.h"

void		move_real_pos(double (*simple_pos)[3], t_objs *obj)
{
  rotate(&(obj->rot), simple_pos, FALSE);
  fill_tab3d(simple_pos, (*simple_pos)[X] + obj->pos[X],
  	     (*simple_pos)[Y] + obj->pos[Y],
  	     (*simple_pos)[Z] + obj->pos[Z]);
}
