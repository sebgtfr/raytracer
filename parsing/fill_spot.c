/*
** fill_spot.c for  in /home/vergez_a/MUL_2014_rtracer/parsing
**
** Made by Luc VERGEZ
** Login   <vergez_a@epitech.net>
**
** Started on  Tue Oct 20 11:49:16 2015 Luc VERGEZ
** Last update Fri Oct 23 15:33:30 2015 sebastien le-maire
*/

#include <stdlib.h>
#include "raytracer.h"

int	p_spot_pos(t_spot *sp, char *str)
{
  int	pos;
  char	**tab;

  pos = 0;
  if ((tab = my_str_to_wordtab(str, " ")) == NULL)
    return (EXIT_FAILURE);
  while (tab[pos] != NULL && (pos < 3))
    {
      sp->pos[pos] = my_atoi(tab[pos]);
      ++pos;
    }
  destroy_strtab(tab);
  return ((pos != 3 || tab[3]) ? my_puterror(MSG_ERR_POS, EXIT_FAILURE)
	  : EXIT_SUCCESS);
}

int	p_spot_col(t_spot *sp, char *str)
{
  if ((str && str[0]) && my_strncmp("0x", str, 2) == 0)
    sp->color = my_atoi_base(str + 2, HEXADECIMAL);
  else if (str && str[0])
    sp->color = my_atoi(str);
  else
    return (my_puterror(MSG_ERR_COL, EXIT_FAILURE));
  return (EXIT_SUCCESS);
}

int		fill_spot(t_spot **sp, FILE *fd)
{
  char		*str;
  t_spot	new;
  int		i;
  int		(*spot_light[2])(t_spot *, char *);

  i = 0;
  spot_light[0] = p_spot_pos;
  spot_light[1] = p_spot_col;
  while ((i < 2) && ((str = get_next_line(fd)) != NULL)
	 && (str[0] != '#'))
    {
      if ((spot_light[i](&new, str)) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      free(str);
      ++i;
    }
  if (i < 2 || new_spot(sp, &(new.pos), new.color))
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
