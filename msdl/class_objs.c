/*
** class_objs.c for raytracer in /home/le-mai_s/recode/TP/raytracer1/Raytracer/mlx
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Thu Sep 10 19:30:32 2015 sebastien le-maire
** Last update Tue Oct 20 14:37:16 2015 sebastien le-maire
*/

#include <stdlib.h>
#include "raytracer_mlx.h"

void		init_class_objs(t_class_objs *objs)
{
  objs->objs = NULL;
  objs->spot = NULL;
  objs->calc_objs[PLANE] = plane;
  objs->calc_objs[SPHERE] = sphere;
  objs->calc_objs[CYLINDER] = cylinder;
  objs->calc_objs[CONE] = cone;
  objs->calc_objs[PARA] = paraboloide;
  objs->calc_objs[HYPER] = hyperboloide;
  objs->calc_objs[DISK] = disk;
  objs->calc_cos[PLANE] = calc_cos_plane;
  objs->calc_cos[SPHERE] = calc_cos_sphere;
  objs->calc_cos[CYLINDER] = calc_cos_cylinder;
  objs->calc_cos[CONE] = calc_cos_cone;
  objs->calc_cos[PARA] = calc_cos_para;
  objs->calc_cos[HYPER] = calc_cos_hyper;
  objs->calc_cos[DISK] = calc_cos_plane;
  objs->calc_norm[PLANE] = calc_norm_plane;
  objs->calc_norm[SPHERE] = calc_norm_sphere;
  objs->calc_norm[CYLINDER] = calc_norm_cylinder;
  objs->calc_norm[CONE] = calc_norm_cone;
  objs->calc_norm[PARA] = calc_norm_para;
  objs->calc_norm[HYPER] = calc_norm_hyper;
  objs->calc_norm[DISK] = calc_norm_plane;
}

int		new_spot(t_spot **spot, double (*pos)[3], unsigned int color)
{
  t_spot	*new;
  t_spot	*last;

  if (!(new = malloc(sizeof(t_spot))))
    return (EXIT_FAILURE);
  fill_tab3d(&(new->pos), (*pos)[X], (*pos)[Y], (*pos)[Z]);
  new->color = color;
  new->next = NULL;
  if (!(*spot))
    *spot = new;
  else
    {
      last = *spot;
      while (last->next)
	last = last->next;
      last->next = new;
    }
  return (EXIT_SUCCESS);
}

void		fill_object(t_objs **elem, t_objs *new)
{
  (*elem)->obj = new->obj;
  fill_tab3d(&((*elem)->pos), new->pos[X], new->pos[Y], new->pos[Z]);
  fill_tab3d(&((*elem)->rot), new->rot[X], new->rot[Y], new->rot[Z]);
  (*elem)->param = new->param;
  (*elem)->limit[MIN] = new->limit[MIN];
  (*elem)->limit[MAX] = new->limit[MAX];
  (*elem)->color[0] = new->color[0];
  (*elem)->color[1] = new->color[1];
  (*elem)->text_pro = new->text_pro;
  (*elem)->shine = new->shine;
  (*elem)->reflection = new->reflection;
  (*elem)->refraction = new->refraction;
  (*elem)->next = NULL;
}

int		new_object(t_objs **main_list, t_objs *new)
{
  t_objs	*elem;
  t_objs	*last;

  if (!(elem = malloc(sizeof(t_objs))))
    return (EXIT_FAILURE);
  fill_object(&elem, new);
  if (!(*main_list))
    *main_list = elem;
  else
    {
      last = *main_list;
      while (last->next)
	last = last->next;
      last->next = elem;
    }
  return (EXIT_SUCCESS);
}

void		destroy_object(t_objs **objs, t_spot **spot)
{
  t_objs	*tmp_objs;
  t_spot	*tmp_spot;

  while (*objs)
    {
      tmp_objs = *objs;
      *objs = (*objs)->next;
      free(tmp_objs);
    }
  while (*spot)
    {
      tmp_spot = *spot;
      *spot = (*spot)->next;
      free(tmp_spot);
    }
}
