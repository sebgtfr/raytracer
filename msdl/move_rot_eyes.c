/*
** move_rot_eyes.c for raytracer in /home/le-mai_s/recode/TP/raytracer1/Raytracer/mlx
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Mon Sep 21 10:44:28 2015 sebastien le-maire
** Last update Mon Sep 21 10:49:48 2015 sebastien le-maire
*/

#include "raytracer.h"

void	        turn_eyes(t_eyes *eyes, int event)
{
  eyes->rot[X] += (event == 0) ? 20 : -20;
}

void	        turn_up_down_eyes(t_eyes *eyes, int event)
{
  eyes->rot[Y] += (event == 0) ? 20 : -20;
}

void	        turn_left_right_eyes(t_eyes *eyes, int event)
{
  eyes->rot[Z] += (event == 0) ? 20 : -20;
}
