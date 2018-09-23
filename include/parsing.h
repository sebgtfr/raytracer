/*
** parsing.h for rt in /home/olivet_a/MUL_2014_rtracer/parsing
**
** Made by OLIVETTI Octave
** Login   <olivet_a@epitech.net>
**
** Started on  Tue Oct 20 14:16:21 2015 OLIVETTI Octave
** Last update Sat Oct 24 18:39:49 2015 sebastien le-maire
*/

#ifndef PARSING_H_
# define PARSING_H_

/*
** fill_eyes.c
*/
int	p_eyes_pos(t_eyes *eyes, char *str);
int	p_eyes_rot(t_eyes *eyes, char *str);
int	fill_eyes(t_eyes *eyes, FILE *fd);

/*
** fill_obj.c
*/
char	**p_tab_of_obj(void);
int	fill_obj(t_objs *objs,FILE *fd, char *name_obj);
int	p_obj_pos(t_objs *objs, char *str);
int	p_obj_rot(t_objs *objs, char *str);
int	p_obj_id(t_objs *objs, char *str);

/*
** parse_col_shine_lim_param.c
*/
int	p_obj_col(t_objs *objs, char *str);
int	p_obj_param(t_objs *objs, char *str);
int	p_obj_limit(t_objs *objs, char *str);
int	p_obj_shine(t_objs *objs, char *str);

/*
** parse_reflect_refract_proc.c
*/
int	p_obj_reflect(t_objs *objs, char *str);
int	p_obj_refract(t_objs *objs, char *str);
int	p_obj_proc(t_objs *objs, char *str);

/*
** fill_spot.c
*/
int	p_spot_pos(t_spot *sp, char *str);
int	p_spot_col(t_spot *sp, char *str);
int	fill_spot(t_spot **sp, FILE *fd);

/*
** main_fill.c
*/
int	my_pars(char *file, t_eyes *eyes,
		t_objs **objs, t_spot **spot);
int	tab_id(FILE *fd,
	       t_eyes *eyes, t_objs **obj,
	       t_spot **spot);

#endif /* !PARSING_H_ */
