/*
** rt_struct.h for raytracer in /home/le-mai_s/recode/TP/raytracer1/new_rtv1/include
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Thu Sep 10 15:48:27 2015 sebastien le-maire
** Last update Sat Oct 24 23:55:59 2015 sebastien le-maire
*/

#ifndef RT_STRUCT_H_
# define RT_STRUCT_H_

# include "rt_macro.h"

/*
** Enumeration of boolean values.
*/
typedef	enum		e_bool
  {
			TRUE,
			FALSE
  }			t_bool;

/*
** Enumeration of limits edge values.
*/
typedef	enum		e_edge_limit
  {
			MIN,
			MAX
  }			t_edgelimit;

/*
** Enumeration of coordonnee to pos tab.
*/
typedef	enum		e_pos
  {
			X,
			Y,
			Z
  }			t_pos;

/*
** Enumeration of color to rgb tab.
*/
typedef	enum		e_color
  {
			R,
			G,
			B
  }			t_color;

/*
** Enumeration of id objects.
*/
typedef	enum		e_id
  {
			PLANE,
			SPHERE,
			CYLINDER,
			CONE,
			PARA,
			HYPER,
			DISK
  }			t_id;

/*
** Struct to object : eyes
*/
typedef	struct		s_eyes
{
  double		pos[3];
  double		rot[3];
  double		vec[3];
  double		k;
  unsigned int		color;
  double		cte_trans;
  int			endian;
}			t_eyes;

/*
** Struct to object : plane, sphere, cylinder, cone.
** param is special parameter of objects :
** For sphere and cylinder, param is ray.
** For cone, param is angle of top.
*/
typedef	struct		s_objs
{
  t_id			obj;
  double		pos[3];
  double		rot[3];
  unsigned int		param;
  int			limit[2];
  unsigned int		color[2];
  t_bool		text_pro;
  double		shine;
  double		reflection;
  double		refraction;
  struct s_objs		*next;
}			t_objs;

/*
** Struct to object : spot
*/
typedef	struct		s_spot
{
  double		pos[3];
  unsigned int		color;
  struct s_spot		*next;
}			t_spot;

/*
** Structure to stock objects and method of calc.
*/
typedef	struct		s_class_objs
{
  t_objs		*objs;
  t_spot		*spot;
  double		(*calc_objs[NB_OBJS])(t_objs *, double (*)[3],
					      double (*)[3], double);
  double		(*calc_cos[NB_OBJS])(double (*)[3], double (*)[3]);
  void			(*calc_norm[NB_OBJS])(double (*)[3], double (*)[3]);
}			t_class_objs;

/*
** Struct to matrix calculation.
*/
typedef	struct		s_matrix
{
  float			m[3][3];
}			t_matrix;

typedef	struct		s_rt_event
{
  int			key_pos_ev;
  int			key_neg_ev;
  void			(*move_eyes)(t_eyes *, int);
}			t_rt_event;

#endif /* !RT_STRUCT */
