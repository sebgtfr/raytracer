/*
** raytracing.c for raytracer in /home/le-mai_s/recode/TP/raytracer1/Raytracer/mlx
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Thu Sep 10 17:18:54 2015 sebastien le-maire
** Last update Sat Oct 24 23:57:51 2015 sebastien le-maire
*/

#include <stdlib.h>
#include "minisdl.h"
#include "raytracer_mlx.h"
#include "rt_libc.h"

t_objs		*inter_objs(t_eyes *eyes, t_class_objs *objs, t_objs *inter)
{
  t_objs	*tmp;
  t_objs	*ret;
  double	k;

  tmp = objs->objs;
  k = eyes->k;
  ret = NULL;
  while (tmp)
    {
      if (tmp != inter)
	{
	  eyes->k = objs->calc_objs[tmp->obj](tmp, &(eyes->pos),
					      &(eyes->vec), k);
	  if (eyes->k != k)
	    {
	      k = eyes->k;
	      ret = tmp;
	    }
	}
      tmp = tmp->next;
    }
  eyes->k = k;
  return (ret);
}

int		progress(int y)
{
  ++y;
  my_putstr(MSG_PROGRESSION);
  my_putnbr(CALC_POURCENT(y, WIN_Y));
  my_putchar(POURCENT);
  return (y);
}

void		raytracing(t_eyes *eyes, t_class_objs *objs, t_msdl *msdl)
{
  int		x;
  int		y;
  t_objs	*obj;

  y = 0;
  while (y < WIN_Y)
    {
      x = -1;
      while (++x < WIN_X)
	{
	  set_eyes(eyes);
	  fill_tab3d(&(eyes->vec), D_EYES_WIN_PROJECT, VEC_X(x), VEC_Y(y));
	  rotate(&(eyes->rot), &(eyes->vec), FALSE);
	  if ((obj = inter_objs(eyes, objs, NULL)))
	    {
	      light_and_shadow(eyes, objs, obj);
	      light_effect(eyes, objs, obj);
	    }
	  msdl_pixel_put(msdl, x, y, eyes->color);
	}
      y = progress(y);
      msdl_update_window(msdl);
    }
  my_putchar(ENDLINE);
}
