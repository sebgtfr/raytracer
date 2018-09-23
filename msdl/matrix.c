/*
** matrix.c for raytracer in /home/le-mai_s/recode/TP/raytracer1/lib
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Thu Jun 25 16:45:54 2015 sebastien le-maire
** Last update Tue Sep 22 13:59:04 2015 sebastien le-maire
*/

#include <math.h>
#include "raytracer_mlx.h"

void	init_matrix(t_matrix *matrix)
{
  matrix->m[0][0] = 1;
  matrix->m[0][1] = 0;
  matrix->m[0][2] = 0;
  matrix->m[1][0] = 0;
  matrix->m[1][1] = 1;
  matrix->m[1][2] = 0;
  matrix->m[2][0] = 0;
  matrix->m[2][1] = 0;
  matrix->m[2][2] = 1;
}

void	calc_matrix(float (*m_main)[3][3], float (*m)[3][3])
{
  int   x;
  int   y;
  float tmp[3][3];

  y = -1;
  while (++y < 3)
    {
      x = -1;
      while (++x < 3)
	tmp[y][x] = (((*m)[y][0] * (*m_main)[0][x]) +
		     ((*m)[y][1] * (*m_main)[1][x]) +
		     ((*m)[y][2] * (*m_main)[2][x]));
    }
  y = -1;
  while (++y < 3)
    {
      x = -1;
      while (++x < 3)
	(*m_main)[y][x] = tmp[y][x];
    }
}

void	rotate_x(t_matrix *matrix, double angle)
{
  float	m[3][3];

  if (angle)
    {
      m[0][0] = 1;
      m[0][1] = 0;
      m[0][2] = 0;
      m[1][0] = 0;
      m[1][1] = (float)cos(RAD(angle));
      m[1][2] = (float)(-sin(RAD(angle)));
      m[2][0] = 0;
      m[2][1] = (float)sin(RAD(angle));
      m[2][2] = (float)cos(RAD(angle));
      calc_matrix(&(matrix->m), &m);
    }
}

void	rotate_y(t_matrix *matrix, double angle)
{
  float	m[3][3];

  if (angle)
    {
      m[0][0] = (float)cos(RAD(angle));
      m[0][1] = 0;
      m[0][2] = (float)sin(RAD(angle));
      m[1][0] = 0;
      m[1][1] = 1;
      m[1][2] = 0;
      m[2][0] = (float)(-sin(RAD(angle)));
      m[2][1] = 0;
      m[2][2] = (float)cos(RAD(angle));
      calc_matrix(&(matrix->m), &m);
    }
}

void	rotate_z(t_matrix *matrix, double angle)
{
  float	m[3][3];

  if (angle)
    {
      m[0][0] = (float)cos(RAD(angle));
      m[0][1] = (float)(-sin(RAD(angle)));
      m[0][2] = 0;
      m[1][0] = (float)sin(RAD(angle));
      m[1][1] = (float)cos(RAD(angle));
      m[1][2] = 0;
      m[2][0] = 0;
      m[2][1] = 0;
      m[2][2] = 1;
      calc_matrix(&(matrix->m), &m);
    }
}
