/*
** my_str_to_wordtab.c for libc in /home/le-mai_s/librairie/librairie_C/libc
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Mon Aug 10 10:33:30 2015 sebastien le-maire
** Last update Mon Oct 19 16:14:08 2015 sebastien le-maire
*/

#include <stdlib.h>
#include "rt_libc.h"

static unsigned int	mstwt_char_str_cmp(const char c,
					   const char *delimit)
{
  unsigned int		pos;

  pos = 0;
  while (delimit[pos])
    {
      if (c == delimit[pos])
	return (0);
      ++pos;
    }
  return (1);
}

static unsigned int	mstwt_count_word(const char *str,
				 const char *delimit)
{
  unsigned int		word;
  unsigned int		pos;

  pos = 0;
  word = 0;
  while (str[pos])
    {
      while ((str[pos]) && (!(mstwt_char_str_cmp(str[pos], delimit))))
	++pos;
      if ((str[pos]) && (mstwt_char_str_cmp(str[pos], delimit)))
	++word;
      while ((str[pos]) && (mstwt_char_str_cmp(str[pos], delimit)))
	++pos;
    }
  return (word);
}

static unsigned int	mstwt_count_char(const char *str,
					 const char *delimit,
					 unsigned int pos)
{
  unsigned int		nb_char;

  nb_char = 0;
  while ((str[pos]) && (mstwt_char_str_cmp(str[pos], delimit)))
    {
      ++nb_char;
      ++pos;
    }
  return (nb_char);
}

char		**my_str_to_wordtab(const char *str, const char *delimit)
{
  char		**tab;
  unsigned int	y;
  unsigned int	pos;
  unsigned int	word;
  unsigned int	nb_char;

  word = mstwt_count_word(str, delimit);
  if (!(tab = malloc(sizeof(char *) * (word + 1))))
    return (NULL);
  tab[word] = NULL;
  y = 0;
  pos = 0;
  while (y < word)
    {
      while ((str[pos]) && (!(mstwt_char_str_cmp(str[pos], delimit))))
	++pos;
      nb_char = mstwt_count_char(str, delimit, pos);
      if (!(tab[y] = newstr(nb_char + 1)))
	return (NULL);
      tab[y] = my_strncpy(tab[y], str + pos, nb_char);
      pos += nb_char;
      ++y;
    }
  return (tab);
}

void		destroy_strtab(char **tab)
{
  unsigned int	y;

  if (!tab)
    return ;
  y = 0;
  while (tab[y])
    free(tab[y++]);
  free(tab);
  tab = NULL;
}
