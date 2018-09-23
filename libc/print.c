/*

** print.c for print in /home/le-mai_s/recode/TP/raytracer1/Raytracer/libc

**

** Made by sebastien le-maire

** Login   <le-mai_s@epitech.net>

**

** Started on  Thu Oct 15 23:07:22 2015 sebastien le-maire

** Last update Thu Oct 15 23:08:27 2015 sebastien le-maire

*/



#include <stdio.h>

#include "rt_libc.h"



void		my_putchar(const char c)

{

  (void)putchar(c);

}



void		my_putstr(const char *str)

{

  unsigned int	i;



  i = 0;

  while (str[i])

    my_putchar(str[i++]);

}

void		my_putnbr(int nb)

{

  if (nb < 0)

    {

      my_putchar('-');

      nb = -nb;

    }

  if (nb >= 10)

    {

      my_putnbr(nb / 10);

      my_putnbr(nb % 10);

    }

  else

    my_putchar(INT_TO_CHAR(nb));

}
