/*

** rt_libc.h for rt_libc in /home/le-mai_s/rendu/Projet_Igraph_repository/MUL_2014_rtracer/include

**

** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>

**

** Started on  Wed Oct 14 13:17:33 2015 sebastien le-maire

** Last update Wed Oct 21 16:28:24 2015 sebastien le-maire

*/



#ifndef RT_LIBC_H_

# define RT_LIBC_H_


# include <stdio.h>


# define ABS(n)			(((n) < 0) ? -n : n)

# define BUFF_SIZE		(50)

# define INT_TO_CHAR(nb)	((nb) + '0')

# define CHAR_TO_INT(nb)	((nb) - '0')

# define IS_NUM(nb)		((nb) >= '0' && (nb) <= '9')

# define HEXADECIMAL		"0123456789ABCDEF"



typedef	struct	s_gnl

{

  char		buf[BUFF_SIZE + 1];

  char		*tmp;

  char		*line;

}		t_gnl;



/*

** my_strcpy.c

*/

char		*strlcpy(char *dest, char *src, int size);

char		*my_strcpy(char *dest, const char *src);

char		*my_strncpy(char *dest, const char *src,
 const unsigned int size);



/*

** my_strcat.c

*/

char		*my_strcat(char *dest, const char *src);



/*

** my_strdup.c

*/

char		*my_strdup(const char *src);



/*

** print.c

*/

void		my_putchar(const char c);

void		my_putstr(const char *str);

void		my_putnbr(int nb);



/*

** my_atoi.c

*/

int		my_atoi(const char *str);

int		my_atoi_base(const char *nbr, const char *base);



/*

** my_strcmp.c

*/

int		my_strcmp(const char *s1, const char *s2);

int		my_strncmp(const char *s1, const char *s2,
 const unsigned int size);



/*

** my_puterror.c

*/

int		my_strlen(const char *str);

int		my_puterror(const char *str, const int err);



/*

** mem.c

*/

char		*newstr(const unsigned int size);

void		*my_memset(void *mem, const unsigned int size);



/*

** my_str_to_wordtab.c
*/

char		**my_str_to_wordtab(const char *str, const char *delimit);

void		destroy_strtab(char **tab);



/*

** get_next_line.c

*/

char		*get_next_line(FILE *file);



#endif /* ! RT_LIBC_H_ */
