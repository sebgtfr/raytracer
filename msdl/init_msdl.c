/*
** init_mlx.c for raytracer in /home/le-mai_s/recode/TP/raytracer1/new_rtv1/mlx
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Thu Sep 10 16:45:44 2015 sebastien le-maire
** Last update Sat Oct 24 23:36:27 2015 sebastien le-maire
*/

#include <stdlib.h>
#include "minisdl.h"
#include "raytracer.h"

int	init_msdl(t_msdl *msdl)
{
  if ((msdl_init(msdl, ALL_OFF) == -1) ||
      (msdl_window(msdl, WIN_X, WIN_Y, "Raytracer minisdl !")))
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
