/*
** raytracer.h for raytracer in /home/le-mai_s/recode/TP/raytracer1/new_rtv1/include
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Thu Sep 10 16:56:40 2015 sebastien le-maire
** Last update Sun Oct 25 00:08:57 2015 sebastien le-maire
*/

#ifndef RAYTRACER_H_
# define RAYTRACER_H_

# include "rt_libc.h"
# include "raytracer_mlx.h"
# include "parsing.h"
# include "verbose.h"

/*
** Main struct of program.
*/
typedef	struct		s_param
{
  t_eyes		eyes;
  t_rt_event		event[NB_EVENT];
  t_class_objs		objs;
}			t_param;

/*
** init_msdl.c
*/
int		init_msdl(t_msdl *msdl);

/*
** event.c
*/
void		init_event(t_rt_event (*event)[NB_EVENT]);
void		fct_key(t_msdl *msdl, int keycode, int mode, t_param *p);

/*
** move_pos_eyes.c
*/
void		forward_back_eyes(t_eyes *eyes, int event);
void	        left_right_pos_eyes(t_eyes *eyes, int event);
void	        up_down_pos_eyes(t_eyes *eyes, int event);

/*
** move_rot_eyes.c
*/
void	        turn_eyes(t_eyes *eyes, int event);
void	        turn_up_down_eyes(t_eyes *eyes, int event);
void	        turn_left_right_eyes(t_eyes *eyes, int event);

#endif /* !RAYTRACER_H_ */
