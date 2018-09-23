/*
** minisdl_struct.h for minisdl in /home/le-mai_s/librairie/minisdl1.x/include
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Fri Aug  7 10:34:18 2015 sebastien le-maire
** Last update Wed Nov 11 19:15:04 2015 sebastien le-maire
*/

#ifndef MINISDL_STRUCT_H_
# define MINISDL_STRUCT_H_

typedef	struct	s_img
{
  SDL_Surface	*img;
}		t_img;

typedef	struct	s_timer
{
  SDL_TimerID	id_timer;
}		t_timer;

typedef	struct	s_mouse
{
  int		x;
  int		y;
}		t_mouse;

typedef	struct	s_music
{
  Mix_Music	*m;
}		t_music;

typedef	struct	s_sound
{
  Mix_Chunk	*s;
}		t_sound;

typedef	struct	s_surface
{
  int		xp;
  int		yp;
  int		xs;
  int		ys;
}		t_surface;

typedef	struct	s_event
{
  SDL_Event	ev;
}		t_event;

typedef	struct	s_msdl
{
  SDL_Surface	*scrn;
  char		opt_win;
  char		continu;
  void		(*key[2])(struct s_msdl *, int, int, void *);
  void		(*mouse[2])(struct s_msdl *, int, t_mouse, void *);
  void		(*motion)(struct s_msdl *, int, int, void *);
  void		(*fct_loop)(struct s_msdl *, void *);
  void		(*fct_mogl)(void *);
  TTF_Font	*font;
  SDL_Surface	*text;
  unsigned char	style;
  SDL_Surface	*(*solid_blended[2])(TTF_Font *, const char *, SDL_Color);
  t_mouse	ms;
}		t_msdl;

#endif /* !MINISDL_STRUCT_H_ */
