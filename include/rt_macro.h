/*
** rt_macro.h for raytracer in /home/le-mai_s/recode/TP/raytracer1/new_rtv1/include
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Thu Sep 10 15:47:34 2015 sebastien le-maire
** Last update Fri Oct 23 14:50:00 2015 sebastien le-maire
*/

#ifndef RT_MACRO_H_
# define RT_MACRO_H_

/*
** Screen and virtual screen
*/
# define WIN_NAME		"Raytracer"
# define WIN_X			(1280)
# define WIN_Y			(720)
# define D_EYES_WIN_PROJECT	((double)500)
# define VEC_X(x)		((double)((WIN_X / 2) - (x)))
# define VEC_Y(y)		((double)((WIN_Y / 2) - (y)))

/*
** Others
*/
# define RAD(a)			(((float)a) * M_PI / 180.0)
# define NB_EVENT		(6)
# define NB_OBJS		(7)
# define NB_PARAM_OBJ		(9)
# define CTE			(-0.1)
# define NORM(x, y, z)		(sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)))
# define REFLECTION(n, v, c)	((-2 * (n)) * (c) + (v))
# define REFRACTION(n, v, c)	((v) + ((c) + sqrt(pow((c), 2))) * (n))

/*
** Msg of progression
*/
# define MSG_PROGRESSION	"\rProgression : "
# define CALC_POURCENT(n, m)	(((n) * 100) / (m))
# define POURCENT		'%'
# define ENDLINE		'\n'

/*
** Intersection objs
*/
# define DELTA(a, b, c)		(pow((b), 2) - 4 * (a) * (c))
# define X0(a, b)		((-(b)) / (2 * (a)))
# define X1(a, b, d)		(((-(b)) - sqrt(d)) / (2 * (a)))
# define X2(a, b, d)		(((-(b)) + sqrt(d)) / (2 * (a)))

/*
** keycode mlx
*/
# define ESCAPE			(65307)
# define TOP_ARROW		(65362)
# define BOTTOM_ARROW		(65364)
# define LEFT_ARROW		(65361)
# define RIGHT_ARROW		(65363)
# define KEY_A			(97)
# define KEY_Z			(122)
# define KEY_E			(101)
# define KEY_R			(114)
# define KEY_D			(100)
# define KEY_F			(102)
# define KEY_C			(99)
# define KEY_V			(118)

/*
** color
*/
# define LIT_ENDIAN		(0)
# define LE_RGB(r, g, b)	(((r) << 16) | ((g) << 8) | (b))
# define BE_RGB(r, g, b)	(((r) >> 16) | ((g) >> 8) | (b))
# define GET_LE_RED(c)		(((c) >> 16) & 0xFF)
# define GET_BE_RED(c)		(((c) << 16) & 0xFF000000)
# define GET_LE_GREEN(c)	(((c) >> 8) & 0xFF)
# define GET_BE_GREEN(c)	(((c) << 8) & 0xFF000000)
# define GET_LE_BLUE(c)		(((c) & 0xFF))
# define GET_BE_BLUE(c)		(((c) & 0xFF000000))
# define WHITE			(0xFFFFFF)
# define BLACK			(0x000000)
# define RED			(0xFF0000)
# define GREEN			(0x00FF00)
# define BLUE			(0x0000FF)
# define GREY			(0x7F7F7F)
# define PURPLE			(0x600099)
# define YELLOW			(0xEFD807)
# define BROWN			(0x582900)
# define ORANGE			(0xDF6D14)
# define PINK			(0xF9429E)
# define TURQUOISE		(0x25FDE9)

/*
** Sphere
*/
# define SPHERE_A(x, y, z)	(pow(x, 2) + pow(y, 2) + pow(z, 2))
# define SPHERE_B(x, y, z)	(2 * (x + y + z))
# define SPHERE_C(x, y, z, r)	(pow(x, 2) + pow(y, 2) + pow(z, 2) - pow(r, 2))

/*
** Plane
*/
# define PLANE_Z(o, s)		(-(o / s))

/*
** Cylinder
*/
# define CYLINDER_A(x, y)	(pow(x, 2) + pow(y, 2))
# define CYLINDER_B(x, y)	(2 * (x + y))
# define CYLINDER_C(x, y, r)	(pow(x, 2) + pow(y, 2) - pow(r, 2))

/*
** Cone
*/
# define CONE_A(x, y, z, a) (pow(x, 2) + pow(y, 2) - (pow(z, 2) / pow(a, 2)))
# define CONE_B(x, y, z, a) ((2 * x) + (2 * y) - (2 * (z / pow(a, 2))))
# define CONE_C(x, y, z, a) (pow(x, 2) + pow(y, 2) - (pow(z, 2) / pow(a, 2)))

/*
** Paraboloide
*/
# define PARA_A(x, y)		(pow(x, 2) + pow(y, 2))
# define PARA_B(x, y, z, c)	((2 * (x + y)) - (z * c))
# define PARA_C(x, y, z, c)	(pow(x, 2) + pow(y, 2) - (z * c))

/*
** hyperaboloide
*/
# define HYPER_A(x, y, z, c) (pow(x, 2) + pow(y, 2) - (c * pow(z, 2)))
# define HYPER_B(x, y, z, c) (2 * (x + y - (c * z)))
# define HYPER_C(x, y, z, c) (pow(x, 2) + pow(y, 2) - (c * pow(z, 2)) - 100)

#endif /* !RT_MACRO */
