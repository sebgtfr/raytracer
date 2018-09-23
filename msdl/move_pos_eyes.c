/*
** move_pos_eyes.c for raytracer in /home/le-mai_s/recode/TP/raytracer1/Raytracer/mlx
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Mon Sep 21 10:36:47 2015 sebastien le-maire
** Last update Mon Sep 21 10:43:40 2015 sebastien le-maire
*/

#include "raytracer.h"

void		forward_back_eyes(t_eyes *eyes, int event)
{
  eyes->pos[X] += (event == 0) ? 20 : -20;
}

void	        left_right_pos_eyes(t_eyes *eyes, int event)
{
  eyes->pos[Y] += (event == 0) ? 20 : -20;
}

void	        up_down_pos_eyes(t_eyes *eyes, int event)
{
  eyes->pos[Z] += (event == 0) ? 20 : -20;
}
