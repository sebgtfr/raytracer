##
## Makefile for raytracer in /home/le-mai_s/recode/TP/raytracer1/new_rtv1
## 
## Made by sebastien le-maire
## Login   <le-mai_s@epitech.net>
## 
## Started on  Thu Sep 10 16:21:59 2015 sebastien le-maire
## Last update Sun Oct 25 00:00:20 2015 sebastien le-maire
##



PATH_MLX	= ./msdl/

PATH_LIBC	= ./libc/

PATH_PRGM	= ./srcs/

PATH_PARS	= ./parsing/



NAME		= raytracer.exe

LIB_NAME	= $(PATH_LIBC)librt_libc.a



CFLAGS		+= -w -Wall -Wextra -Werror

CFLAGS		+= -I./include

CFLAGS		+= -I./../../lib/minisdl1.x/include



LDFLAGS		+= -L../minisdl-c-v0.0/ -lmsdl
LDFLAGS		+= -lmingw32 -lSDLmain -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf

LDFLAGS		+= -lm

LDFLAGS		+= -L$(PATH_LIBC) -lrt_libc



SRCS_LIB	+= $(PATH_LIBC)my_strcpy.c
SRCS_LIB	+= $(PATH_LIBC)my_puterror.c
SRCS_LIB	+= $(PATH_LIBC)print.c
SRCS_LIB	+= $(PATH_LIBC)my_atoi.c
SRCS_LIB	+= $(PATH_LIBC)my_strcmp.c
SRCS_LIB	+= $(PATH_LIBC)mem.c
SRCS_LIB	+= $(PATH_LIBC)my_strcat.c
SRCS_LIB	+= $(PATH_LIBC)my_strdup.c
SRCS_LIB	+= $(PATH_LIBC)my_str_to_wordtab.c
SRCS_LIB	+= $(PATH_LIBC)get_next_line.c

SRCS		+= $(PATH_PARS)main_fill.c
SRCS		+= $(PATH_PARS)fill_eyes.c
SRCS		+= $(PATH_PARS)fill_obj.c
SRCS		+= $(PATH_PARS)parse_col_shine_lim_param.c
SRCS		+= $(PATH_PARS)parse_reflect_refract_proc.c
SRCS		+= $(PATH_PARS)fill_spot.c
SRCS		+= $(PATH_MLX)init_msdl.c
SRCS		+= $(PATH_MLX)move_pos_eyes.c
SRCS		+= $(PATH_MLX)move_rot_eyes.c
SRCS		+= $(PATH_MLX)event.c
SRCS		+= $(PATH_MLX)eyes.c
SRCS		+= $(PATH_MLX)matrix.c
SRCS		+= $(PATH_MLX)rotate.c
SRCS		+= $(PATH_MLX)class_objs.c
SRCS		+= $(PATH_MLX)calc_objs.c
SRCS		+= $(PATH_MLX)paraboloide.c
SRCS		+= $(PATH_MLX)hyperboloide.c
SRCS		+= $(PATH_MLX)disk.c
SRCS		+= $(PATH_MLX)eq_trinome.c
SRCS		+= $(PATH_MLX)calc_cos.c
SRCS		+= $(PATH_MLX)calc_norm.c
SRCS		+= $(PATH_MLX)color.c
SRCS		+= $(PATH_MLX)move_real_pos.c
SRCS		+= $(PATH_MLX)calc_light_shadow.c
SRCS		+= $(PATH_MLX)damier.c
SRCS		+= $(PATH_MLX)light_and_shadow.c
SRCS		+= $(PATH_MLX)limits_objs.c
SRCS		+= $(PATH_MLX)light_effect.c
SRCS		+= $(PATH_MLX)reflection.c
SRCS		+= $(PATH_MLX)refraction.c
SRCS		+= $(PATH_MLX)raytracing.c
SRCS		+= $(PATH_PRGM)main.c

OBJS		= $(SRCS:.c=.o)

OBJS_LIB	= $(SRCS_LIB:.c=.o)

CC		= gcc

AR		= ar rc

RAN		= ranlib

RM		= rm -f

all: $(LIB_NAME) $(NAME)

$(LIB_NAME): $(OBJS_LIB)
	$(AR) $(LIB_NAME) $(OBJS_LIB)
	$(RAN) $(LIB_NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_LIB)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIB_NAME)

re: fclean all

.PHONY: all clean fclean re
