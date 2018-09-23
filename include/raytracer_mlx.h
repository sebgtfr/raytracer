/*
** raytracer.h for raytracer in /home/le-mai_s/recode/TP/raytracer1/new_rtv1/raytracer
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Thu Sep 10 15:40:20 2015 sebastien le-maire
** Last update Sun Oct 25 00:07:22 2015 sebastien le-maire
*/

#ifndef RAYTRACER_MLX_H_
# define RAYTRACER_MLX_H_

# include "rt_struct.h"
# include "minisdl.h"

/*
** matrix.c
*/
void		init_matrix(t_matrix *matrix);
void		calc_matrix(float (*m_main)[3][3], float (*m)[3][3]);
void		rotate_x(t_matrix *matrix, double angle);
void		rotate_y(t_matrix *matrix, double angle);
void		rotate_z(t_matrix *matrix, double angle);

/*
** rotate.c
*/
void		calc_matrix_pt(t_matrix *m, double (*pt)[3]);
void		rotate(double (*angle)[3], double (*pt)[3], t_bool inversed);

/*
** eyes.c
*/
void		fill_tab3d(double (*tab3d)[3], double x, double y, double z);
void		init_eyes(t_eyes *eyes, double x, double y, double z);
void		init_tmp_eyes(t_eyes *eyes, double (*pos)[3],
			      double (*vec)[3], double k);
void	        set_eyes(t_eyes *eyes);

/*
** class_objs.c
*/
void		init_class_objs(t_class_objs *objs);
int		new_spot(t_spot **spot, double (*pos)[3], unsigned int color);
int		new_object(t_objs **main_list, t_objs *new);
void		fill_object(t_objs **elem, t_objs *new);
void		destroy_object(t_objs **objs, t_spot **spot);

/*
** calc_objs.c
*/
double	        plane(t_objs *s, double (*pos)[3],
		      double (*vec)[3], double k);
double	        sphere(t_objs *s, double (*pos)[3],
		       double (*vec)[3], double k);
double	        cylinder(t_objs *s, double (*pos)[3],
			 double (*vec)[3], double k);
double	        cone(t_objs *s, double (*pos)[3],
		     double (*vec)[3], double k);

/*
** paraboloide.c
*/
double		paraboloide(t_objs *o, double (*pos)[3],
			     double (*vec)[3], double k);
void		calc_norm_para(double (*norm)[3], double (*inter)[3]);
double		calc_cos_para(double (*inter)[3], double (*light)[3]);

/*
** hyperboloide.c
*/
double		hyperboloide(t_objs *o, double (*pos)[3],
			     double (*vec)[3], double k);
void		calc_norm_hyper(double (*norm)[3], double (*inter)[3]);
double		calc_cos_hyper(double (*inter)[3], double (*light)[3]);

/*
** disk.c
*/
double	        disk(t_objs *o, double (*pos)[3],
		     double (*vec)[3], double k);

/*
** eq_trinome.c
*/
double		eq_trinome(double a, double b, double c, double old_k);
double		eq_back_trinome(double a, double b, double c);

/*
** calc_cos.c
*/
double		calc_cos_sphere(double (*inter)[3], double (*light)[3]);
double		calc_cos_plane(double (*inter)[3], double (*light)[3]);
double		calc_cos_cylinder(double (*inter)[3], double (*light)[3]);
double		calc_cos_cone(double (*inter)[3], double (*light)[3]);

/*
** calc_norm.c
*/
void		calc_norm_sphere(double (*norm)[3], double (*inter)[3]);
void		calc_norm_cylinder(double (*norm)[3], double (*inter)[3]);
void		calc_norm_plane(double (*norm)[3], double (*inter)[3]);
void		calc_norm_cone(double (*norm)[3], double (*inter)[3]);

/*
** color.c
*/
void		separate_rgb(unsigned int (*rgb)[3], unsigned int color,
			     const int endian);
unsigned int	fusion_rgb(unsigned int (*rgb)[3], const int endian);

/*
** move_real_pos.c
*/
void		move_real_pos(double (*simple_pos)[3], t_objs *obj);

/*
** calc_light_shadow.c
*/
void		calc_inter(double (*inter)[3], t_objs *obj_inter,
			   t_eyes *eyes);
void		calc_light(double (*light_vec)[3], double (*inter)[3],
			   t_spot *spot, t_objs *obj_inter);

/*
** light_and_shadow.c
*/
double		shadow(t_class_objs *objs, t_objs *obj_inter,
		       double (*pos_spot)[3], double (*inter)[3]);
void		light_and_shine(t_eyes *eyes, t_objs *inter_objs,
				t_spot *spot, double cos);
void		light_and_shine_damier(t_eyes *eyes, t_objs *obj_inter,
				       t_spot *spot, double cos);
void		light_and_shadow(t_eyes *eyes, t_class_objs *objs,
				 t_objs *obj_inter);

/*
** limits_objs.c
*/
int		limit_plane(t_objs *obj, double (*inter)[3]);
int		limit_disk(t_objs *obj, double (*inter)[3]);
int		limits_objs(t_objs *obj, t_eyes *eyes, double k);

/*
** light_effect.c
*/
void		light_effect(t_eyes *eyes, t_class_objs *objs,
			     t_objs *obj_inter);

/*
** reflection.c
*/
void		reflection(t_eyes *eyes, t_class_objs *objs,
			   t_objs *obj_inter, t_eyes *new);
void		calc_vision(double (*vision)[3], double (*inter)[3],
			    double (*pos_eyes)[3]);
void		calc_reflection_vector(double (*reflection)[3],
				       double (*norm)[3],
				       double (*vision)[3],
				       double c);

/*
** refraction.c
*/
void		refraction(t_eyes *eyes, t_class_objs *objs,
			   t_objs *obj_inter, t_eyes *new);
void		calc_vision(double (*vision)[3], double (*inter)[3],
			    double (*pos_eyes)[3]);
void		calc_refraction_vector(double (*refraction)[3],
				       double (*norm)[3],
				       double (*vision)[3],
				       double c);

/*
** damier.c
*/
int		damier(double x, double y, t_bool damier_on);

/*
** raytracing.c
*/
int		progress(int y);
void		raytracing(t_eyes *eyes, t_class_objs *objs, t_msdl *msdl);
t_objs		*inter_objs(t_eyes *eyes, t_class_objs *objs, t_objs *inter);

#endif /* !RAYTRACER_MLX_H_ */
