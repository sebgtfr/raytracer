/*
** event.c for raytracer in /home/le-mai_s/recode/TP/raytracer1/new_rtv1/mlx
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Thu Sep 10 16:46:35 2015 sebastien le-maire
** Last update Sun Oct 25 00:09:10 2015 sebastien le-maire
*/

#include <stdlib.h>

#include "raytracer.h"

void		init_event(t_rt_event (*event)[NB_EVENT])
{
  (*event)[0].key_pos_ev = SDLK_UP;
  (*event)[0].key_neg_ev = SDLK_DOWN;
  (*event)[0].move_eyes = forward_back_eyes;
  (*event)[1].key_pos_ev = SDLK_LEFT;
  (*event)[1].key_neg_ev = SDLK_RIGHT;
  (*event)[1].move_eyes = left_right_pos_eyes;
  (*event)[2].key_pos_ev = SDLK_a;
  (*event)[2].key_neg_ev = SDLK_z;
  (*event)[2].move_eyes = up_down_pos_eyes;
  (*event)[3].key_pos_ev = SDLK_e;
  (*event)[3].key_neg_ev = SDLK_r;
  (*event)[3].move_eyes = turn_eyes;
  (*event)[4].key_pos_ev = SDLK_d;
  (*event)[4].key_neg_ev = SDLK_f;
  (*event)[4].move_eyes = turn_up_down_eyes;
  (*event)[5].key_pos_ev = SDLK_c;
  (*event)[5].key_neg_ev = SDLK_v;
  (*event)[5].move_eyes = turn_left_right_eyes;
}

void		fct_key(t_msdl *msdl, int keycode,
			__attribute__((unused))int mode, t_param *p)
{
  unsigned int	event;

  if (keycode == SDLK_ESCAPE)
    {
      destroy_object(&(p->objs.objs), &(p->objs.spot));
      exit(EXIT_SUCCESS);
    }
  else
    {
      event = 0;
      while ((event < NB_EVENT) && (keycode != p->event[event].key_pos_ev &&
      				    keycode != p->event[event].key_neg_ev))
	++event;
      if (event < NB_EVENT)
	{
	  p->event[event].move_eyes(&(p->eyes),
				    keycode - p->event[event].key_pos_ev);
	  raytracing(&(p->eyes), &(p->objs), msdl);
	}
    }
}
