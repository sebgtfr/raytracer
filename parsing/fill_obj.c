/*
** fill_obj.c for  in /home/vergez_a/MUL_2014_rtracer/parsing
**
** Made by Luc VERGEZ
** Login   <vergez_a@epitech.net>
**
** Started on  Tue Oct 20 13:28:59 2015 Luc VERGEZ
** Last update Fri Oct 23 15:23:45 2015 sebastien le-maire
*/

#include <stdlib.h>
#include "raytracer.h"

char	**p_tab_of_obj(void)
{
  char	**tab;
  int	i;

  if (!(tab = malloc(sizeof(char *) * (NB_OBJS + 1))))
    return (NULL);
  tab[PLANE] = my_strdup("#PLANE");
  tab[SPHERE] = my_strdup("#SPHERE");
  tab[CYLINDER] = my_strdup("#CYLINDER");
  tab[CONE] = my_strdup("#CONE");
  tab[PARA] = my_strdup("#PARA");
  tab[HYPER] = my_strdup("#HYPER");
  tab[DISK] = my_strdup("#DISK");
  tab[NB_OBJS] = NULL;
  i = 0;
  while (tab[i])
    i++;
  return ((i != NB_OBJS) ? NULL : tab);
}

int	fill_obj(t_objs *objs,FILE *fd, char *name_obj)
{
  int	(*new_obj[NB_PARAM_OBJ])(t_objs *, char *);
  int	i;
  char	*str;

  new_obj[0] = p_obj_pos;
  new_obj[1] = p_obj_rot;
  new_obj[2] = p_obj_param;
  new_obj[3] = p_obj_limit;
  new_obj[4] = p_obj_col;
  new_obj[5] = p_obj_shine;
  new_obj[6] = p_obj_reflect;
  new_obj[7] = p_obj_refract;
  new_obj[8] = p_obj_proc;
  i = -1;
  if (p_obj_id(objs, name_obj) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  while ((++i < NB_PARAM_OBJ) && ((str = get_next_line(fd)))
	 && (str[0] != '#'))
    {
      if ((new_obj[i](objs, str)) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      free(str);
    }
  return ((i < NB_PARAM_OBJ) ? my_puterror(MSG_ERR_NB_PARAM_OBJ, EXIT_FAILURE)
	  : EXIT_SUCCESS);
}

int	p_obj_id(t_objs *objs, char *str)
{
  char	**tab;
  int	i;

  if (!(tab = p_tab_of_obj()))
    return (my_puterror(MSG_ERR_MALLOC ,EXIT_FAILURE));
  i = 0;
  while ((i < NB_OBJS) && my_strcmp(str, tab[i]))
    ++i;
  if (i == NB_OBJS)
    return (my_puterror(MSG_ERR_OBJ_NOT_FOUND, EXIT_FAILURE));
  objs->obj = i;
  destroy_strtab(tab);
  return (EXIT_SUCCESS);
}

int	p_obj_pos(t_objs *objs, char *str)
{
  int	i;
  char	**tab;

  i = 0;
  if ((tab = my_str_to_wordtab(str, " ")) == NULL)
    return (my_puterror(MSG_ERR_MALLOC ,EXIT_FAILURE));
  while ((tab[i]) && (i < 3))
    {
      objs->pos[i] = my_atoi(tab[i]);
      ++i;
    }
  destroy_strtab(tab);
  return ((i != 3 || tab[3]) ? my_puterror(MSG_ERR_POS, EXIT_FAILURE)
	  : EXIT_SUCCESS);
}

int	p_obj_rot(t_objs *objs, char *str)
{
  int	i;
  char	**tab;

  i = 0;
  if ((tab = my_str_to_wordtab(str, " ")) == NULL)
    return (my_puterror(MSG_ERR_MALLOC ,EXIT_FAILURE));
  while ((tab[i] != NULL) && (i < 3))
    {
      objs->rot[i] = my_atoi(tab[i]);
      ++i;
    }
  destroy_strtab(tab);
  return ((i != 3 || tab[3]) ? my_puterror(MSG_ERR_ROT, EXIT_FAILURE)
	  : EXIT_SUCCESS);
}
