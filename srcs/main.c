/*

** main.c for raytracer in /home/le-mai_s/recode/TP/raytracer1/new_rtv1/srcs

**

** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**

** Started on  Thu Sep 10 16:29:07 2015 sebastien le-maire

** Last update Sun Oct 25 00:03:19 2015 sebastien le-maire

*/



#include <stdio.h>
#include <stdlib.h>
#include "raytracer.h"



int		main(int ac, char **av)

{

  t_param	p;

  t_msdl	msdl;
  char		*file;

  (void)ac;
  (void)av;
  init_event(&(p.event));

  init_eyes(&(p.eyes), -40, 0, 100);

  init_class_objs(&(p.objs));

  (void)printf("Entrez le nom du fichier de votre scene : ");
  if (!(file = get_next_line(stdin)))
    return (my_puterror("Error: get_line failed !\n", EXIT_FAILURE));
  if (my_pars(file, &(p.eyes), &(p.objs.objs), &(p.objs.spot)))

    return (EXIT_FAILURE);
  free(file);

  if (init_msdl(&msdl) == EXIT_FAILURE)

    return (my_puterror(MSG_ERR_INIT_MSDL, EXIT_FAILURE));

  p.eyes.endian = 0;

  raytracing(&(p.eyes), &(p.objs), &msdl);

  msdl_key_event(&msdl, fct_key, NULL);

  msdl_event_loop(&msdl, &p);

  msdl_end(&msdl);

  return (EXIT_SUCCESS);

}
