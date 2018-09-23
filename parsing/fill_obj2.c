/*
** fill_obj2.c for  in /home/vergez_a/MUL_2014_rtracer/parsing
**
** Made by Luc VERGEZ
** Login   <vergez_a@epitech.net>
**
** Started on  Tue Oct 20 14:29:53 2015 Luc VERGEZ
** Last update Fri Oct 23 15:33:45 2015 sebastien le-maire
*/

#include <stdlib.h>
#include "raytracer.h"

int	p_obj_col(t_objs *objs, char *str)
{
  char	**tab;
  int	i;

  if ((tab = my_str_to_wordtab(str, " ")) == NULL)
    return (my_puterror(MSG_ERR_MALLOC ,EXIT_FAILURE));
  i = 0;
  while ((tab[i]) && (i < 2))
    {
      if ((str) && my_strncmp("0x", tab[i], 2) == 0)
	objs->color[i] = my_atoi_base(tab[i] + 2, HEXADECIMAL);
      else if (str)
	objs->color[i] = my_atoi(tab[i]);
      else
	return (my_puterror(MSG_ERR_COL, EXIT_FAILURE));
      ++i;
    }
  destroy_strtab(tab);
  return ((i != 2 || tab[2]) ? my_puterror(MSG_ERR_NB_COL_OBJS, EXIT_FAILURE)
	  : EXIT_SUCCESS);
}

int	p_obj_param(t_objs *objs, char *str)
{
  int	nb;

  if ((str) && ((nb = my_atoi(str)) > 0))
    objs->param = nb;
  else if (objs->obj != PLANE)
    return (my_puterror(MSG_ERR_PARAM_OBJ, EXIT_FAILURE));
  return (EXIT_SUCCESS);
}

int	p_obj_limit(t_objs *objs, char *str)
{
  int	i;
  char	**tab;

  i = 0;
  if ((tab = my_str_to_wordtab(str, " ")) == NULL)
    return (my_puterror(MSG_ERR_MALLOC ,EXIT_FAILURE));
  while (tab[i])
    {
      objs->limit[i] = my_atoi(tab[i]);
      ++i;
    }
  destroy_strtab(tab);
  return ((i != 2) ? my_puterror(MSG_ERR_NB_LIM_OBJS, EXIT_FAILURE)
	  : EXIT_SUCCESS);
}

int	p_obj_shine(t_objs *objs, char *str)
{
  if (str != NULL && str[0])
    {
      objs->shine = ABS((((double)my_atoi(str)) / 10000.0));
      if (objs->shine > 1)
	objs->shine = 1;
      else if (objs->shine < 0)
	objs->shine = 0;
      return (EXIT_SUCCESS);
    }
  return (my_puterror(MSG_ERR_SHINE, EXIT_FAILURE));
}
