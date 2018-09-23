/*

** fill_new_obj.c for  in /home/vergez_a/MUL_2014_rtracer/parsing

**

** Made by Luc VERGEZ

** Login   <vergez_a@epitech.net>

**

** Started on  Mon Oct 19 11:04:21 2015 Luc VERGEZ

** Last update Fri Oct 23 15:18:15 2015 sebastien le-maire

*/



#include <stdlib.h>
#include <sys/types.h>

#include <sys/stat.h>

#include <fcntl.h>

#include "raytracer.h"



int		my_pars(char *file, t_eyes *eyes,
 t_objs **objs, t_spot **spot)

{

  FILE		*fd;



  if (((fd = fopen(file, "r")) == NULL))

    return (my_puterror(MSG_ERR_OPEN, EXIT_FAILURE));
  if (tab_id(fd, eyes, objs, spot) == EXIT_FAILURE)

    return (EXIT_FAILURE);

  return (EXIT_SUCCESS);

}



int		tab_id(FILE *fd, t_eyes *eyes, t_objs **obj, t_spot **spot)

{

  char		*str;

  t_objs	new;



  while (((str = get_next_line(fd)) != NULL) && (str[0]))

    {
      if (my_strcmp("#SPOT", str) == 0)

	{

	  if ((fill_spot(spot, fd)) == EXIT_FAILURE)

	    return (my_puterror(MSG_ERR_SPOT, EXIT_FAILURE));

	}

      else if (my_strcmp("#EYES", str) == 0)

	{

	  if ((fill_eyes(eyes, fd)) == EXIT_FAILURE)

	    return (my_puterror(MSG_ERR_EYES, EXIT_FAILURE));

	}

      else

	{

	  if (((fill_obj(&new, fd, str)) == EXIT_FAILURE) ||
 new_object(obj, &new) == EXIT_FAILURE)

	    return (my_puterror(MSG_ERR_OBJS, EXIT_FAILURE));

	}

      free(str);

    }
 
 return (EXIT_SUCCESS);

}
