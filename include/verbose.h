/*
** verbose.h for raytracer in /home/le-mai_s/recode/TP/raytracer1/Raytracer/include
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Fri Oct 23 11:41:43 2015 sebastien le-maire
** Last update Sun Oct 25 00:01:08 2015 sebastien le-maire
*/

#ifndef VERBOSE_H_
# define VERBOSE_H_

/*
** Verbose error mlx
*/
# define MSG_ERR_INIT_MSDL	"Error: initialisation of minisdl failed !\n"

/*
** Verbose param
*/
# define MSG_ERR_NB_ARG		"Usage: ./rt file\n"

/*
** Verbose malloc
*/
# define MSG_ERR_MALLOC		"Error: allocation of memory failed !\n"

/*
** Verbose parsing
*/
# define MSG_ERR_OPEN		"Error: Open of file failed !\n"
# define MSG_ERR_SPOT		"=> initialisation of spot failed !\n"
# define MSG_ERR_EYES		"=> initialisation of eyes failed !\n"
# define MSG_ERR_OBJS		"=> initialisation of object failed !\n"
# define MSG_ERR_POS		"Error: Possition [x] [y] [z]\n"
# define MSG_ERR_ROT		"Error: Rotation [x] [y] [z]\n"
# define MSG_ERR_COL		"Error: Color is missing\n"
# define MSG_ERR_OBJ_NOT_FOUND	"Error: Object not found !\n"
# define MSG_ERR_NB_PARAM_OBJ	"Error: Object incomplete !\n"
# define MSG_ERR_NB_COL_OBJS	"Error: Color [color one] [color two]\n"
# define MSG_ERR_PARAM_OBJ	"Error: Param is positive numbers !\n"
# define MSG_ERR_NB_LIM_OBJS	"Error: limits [min] [max]!\n"
# define MSG_ERR_SHINE		"Error: Shine is missing\n"
# define MSG_ERR_REFLECT	"Error: Reflection is missing\n"
# define MSG_ERR_REFRACT	"Error: Refraction is missing\n"
# define MSG_ERR_PROC		"Error: procedural texture is missing\n"

#endif /* !VERBOSE_H_ */
