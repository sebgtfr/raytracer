/*
** fill_obj3.c for  in /home/vergez_a/MUL_2014_rtracer/parsing
**
** Made by Luc VERGEZ
** Login   <vergez_a@epitech.net>
**
** Started on  Wed Oct 21 15:14:28 2015 Luc VERGEZ
** Last update Fri Oct 23 15:29:44 2015 sebastien le-maire
*/

#include <stdlib.h>
#include "raytracer.h"

int	p_obj_reflect(t_objs *objs, char *str)
{
  if (str != NULL && str[0])
    {
      objs->reflection = ABS((((double)my_atoi(str)) / 10000.0));
      if (objs->reflection > 1)
	objs->reflection = 1;
      else if (objs->reflection < 0)
	objs->reflection = 0;
      return (EXIT_SUCCESS);
    }
  return (my_puterror(MSG_ERR_REFLECT, EXIT_FAILURE));
}

int	p_obj_refract(t_objs *objs, char *str)
{
  if (str != NULL && str[0])
    {
      objs->refraction = ABS((((double)my_atoi(str)) / 10000.0));
      if (objs->refraction > 1)
	objs->refraction = 1;
      else if (objs->refraction < 0)
	objs->refraction = 0;
      return (EXIT_SUCCESS);
    }
  return (my_puterror(MSG_ERR_REFRACT, EXIT_FAILURE));
}

int	p_obj_proc(t_objs *objs, char *str)
{
  int	nb;

  if (str != NULL && str[0])
    {
      nb = my_atoi(str);
      if (nb == 0)
	objs->text_pro = 0;
      else
	objs->text_pro = 1;
      return (EXIT_SUCCESS);
    }
  return (my_puterror(MSG_ERR_PROC, EXIT_FAILURE));
}
