/*
** make_fill.c for rt in /home/olivet_a/MUL_2014_rtracer/parsing
**
** Made by OLIVETTI Octave
** Login   <olivet_a@epitech.net>
**
** Started on  Mon Oct 19 15:17:36 2015 OLIVETTI Octave
** Last update Fri Oct 23 14:22:09 2015 sebastien le-maire
*/

#include <stdlib.h>
#include "raytracer.h"

int	p_eyes_pos(t_eyes *eyes, char *str)
{
  int	pos;
  char	**tab;

  pos = 0;
  if ((tab = my_str_to_wordtab(str, " ")) == NULL)
    return (EXIT_FAILURE);
  while (tab[pos] && (pos < 3))
    {
      eyes->pos[pos] = my_atoi(tab[pos]);
      ++pos;
    }
  destroy_strtab(tab);
  return ((pos != 3 || tab[3]) ? my_puterror(MSG_ERR_POS, EXIT_FAILURE)
	  : EXIT_SUCCESS);
}

int	p_eyes_rot(t_eyes *eyes, char *str)
{
  int	pos;
  char	**tab;

  pos = 0;
  if ((tab = my_str_to_wordtab(str, " ")) == NULL)
    return (EXIT_FAILURE);
  while (tab[pos] && (pos < 3))
    {
      eyes->rot[pos] = my_atoi(tab[pos]);
      ++pos;
    }
  destroy_strtab(tab);
  return ((pos != 3 || tab[3]) ? my_puterror(MSG_ERR_ROT, EXIT_FAILURE)
	  : EXIT_SUCCESS);
}

int	fill_eyes(t_eyes *eyes, FILE *fd)
{
  char	*str;
  int	accu;
  int	(*eye_ball[2])(t_eyes *, char *);

  accu = 0;
  eye_ball[0] = p_eyes_pos;
  eye_ball[1] = p_eyes_rot;
  while ((accu < 2) && ((str = get_next_line(fd)) != NULL)
	 && (str[0] != '#'))
    {
      if ((eye_ball[accu](eyes, str)) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      free(str);
      ++accu;
    }
  return ((accu < 2) ? EXIT_FAILURE : EXIT_SUCCESS);
}
