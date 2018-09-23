/*
** limits_objs.c for raytracer.c in /home/le-mai_s/recode/TP/raytracer1/Raytracer/mlx
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Wed Sep 30 11:58:18 2015 sebastien le-maire
** Last update Thu Oct 15 22:14:42 2015 sebastien le-maire
*/

#include "raytracer_mlx.h"

int		limit_disk(t_objs *obj, double (*inter)[3])
{
  if ((obj->limit[MAX] - obj->limit[MIN]) > 0)
    return (((*inter)[X] < obj->limit[MAX] && (*inter)[X] > obj->limit[MIN]) ?
	    1 : 0);
  return (1);
}

int		limit_plane(t_objs *obj, double (*inter)[3])
{
  double	k[2];

  if (obj->limit[MIN] && obj->limit[MAX])
    {
      k[0] = obj->limit[MIN] * (*inter)[Y];
      k[0] /= (obj->limit[MAX] * obj->limit[MIN]);
      k[1] = (*inter)[X] / obj->limit[MIN];
      if (k[0] > 0 && k[0] < 1 && k[1] > 0 && k[1] < 1)
	return (1);
      return (0);
    }
  return (1);
}

int		limits_objs(t_objs *obj, t_eyes *eyes, double k)
{
  double	inter[3];

  if ((obj->limit[MAX] - obj->limit[MIN]) > 0)
    {
      calc_inter(&inter, obj, eyes);
      if ((inter[Z] < obj->limit[MAX] && inter[Z] > obj->limit[MIN]))
	return (1);
      if (k < 0)
	return (0);
      eyes->k = k;
      calc_inter(&inter, obj, eyes);
      return ((inter[Z] < obj->limit[MAX] && inter[Z] > obj->limit[MIN])
	      ? 1 : 0);
    }
  return (1);
}
