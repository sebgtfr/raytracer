/*
** minisdl.h for minisdl in /home/le-mai_s/recode/SDL/test1
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Wed May 27 17:37:12 2015 sebastien le-maire
** Last update Wed Nov 11 19:18:29 2015 sebastien le-maire
*/

#ifndef MINISDL_H_
# define MINISDL_H_

# include <SDL/SDL.h>
# include <SDL/SDL_image.h>
# include <SDL/SDL_mixer.h>
# include <SDL/SDL_ttf.h>
# include "minisdl_struct.h"
# include "minisdl_macro.h"

/*
** Command compilation is :
** -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -L[way] -lmsdl
*/

int		msdl_init(t_msdl *msdl, char choice_opt);
/*
** Return -1 if failed.
*/

int		msdl_window(t_msdl *msdl, int width,
			    int height, char *title);
/*
** Return 0 if Success.
*/

void		msdl_pixel_put(t_msdl *msdl, int x, int y, unsigned int color);
void		msdl_clear_window(t_msdl *msdl);
void		msdl_update_window(t_msdl *msdl);
void		msdl_end(t_msdl *msdl);

/*
** Surface stuff
*/

void		msdl_surface_init_pos(t_surface *pos_size, int x, int y);
void		msdl_surface_init_size(t_surface *pos_size, int x, int y);
int		msdl_create_surface(t_msdl *msdl, t_surface *pos_size,
				    int color);
/*
** Return 0 if failed. We need only one structure t_surface.
*/

/*
** Image stuff
*/

void		msdl_put_icon(char *name_img);
/*
** Warning ! msdl_put_icon must be use before msdl_window
*/

int		msdl_save_image_bmp(t_img *param_img, char *name_img);
/*
** Return 1 if failed, 0 if Success.
*/

int		msdl_save_image(t_img *param_img, char *name_img);
/*
** Return 1 if failed, 0 if Success.
*/

void		msdl_add_transparence_to_color_in_image(t_img *param_img,
							int color);
/*
** Warning ! msdl_add_transparence_to_color_in_image must be use before
** msdl_put_image
*/

void		msdl_add_alpha_to_image(t_img *param_img, char transparency);
/*
** Warning ! msdl_add_Alpha_to_image must be use before msdl_put_image,
** transparency is a number from 0 to 255, he's contains in char.
*/

void		msdl_cpy_image(t_img *img_dest, t_img *img_src);
void		msdl_put_image(t_msdl *msdl, t_img *param_img, int x, int y);
void		msdl_destroy_image(t_img *param_img);

/*
** Event stuff
*/

void		msdl_key_autorepeaton(int wait, int period);
void		msdl_key_event(t_msdl *msdl, void (*fct_keypress)(),
			       void (*fct_keyrelease)());
/*
** You can use SDL Flags for event key in liSDL.
** prototype : void fct(t_msdl *msdl, int keycode, int mode, void *param)
*/

void		msdl_tmp_keypress_event(t_msdl *msdl, t_event *event,
					void (*fct)(), void *param);
/*
** permit to create event key_press will use only one time by call function.
** this not loop, just for immediate event.
*/

void		msdl_tmp_keyrelease_event(t_msdl *msdl, t_event *event,
					  void (*fct)(), void *param);
/*
** Idem to tmp_keypress but for key_release
*/


void		msdl_mouse_event(t_msdl *msdl, void (*fct_mousepress)(),
				 void (*fct_mouserelease)(),
				 void (*fct_mousemotion)());
/*
** prototype : void fct(t_msdl *msdl, int buttom, t_mouse mouse, void *param)
** prototype motion : void fct(t_msdl *msdl, int x, int y, void *param)
*/

void		msdl_tmp_mousepress_event(t_msdl *msdl, t_event *event,
					  void (*fct)(), void *param);
/*
** Idem to tmp_keypress but for mouse_press.
*/

void		msdl_tmp_mouserelease_event(t_msdl *msdl, t_event *event,
					    void (*fct)(), void *param);
/*
** Idem to tmp_keypress but for mouse_release.
*/

void		msdl_tmp_mousemotion_event(t_msdl *msdl, t_event *event,
					   void (*fct)(), void *param);
/*
** Idem to tmp_keypress but for mouse_motion.
*/

void		msdl_fct_loop_event(t_msdl *msdl, void (*fct_main)());
/*
** prototype : void  fct(t_msdl *msdl, void *param)
*/

int		msdl_add_mogl(t_msdl *msdl, void (*fct_miniopengl)());
/*
** msdl_add_mogl can be use only if OPENGL_ON is actif.
** prototype function OpenGL : void  fct_OpenGL(void *param);
*/

void		msdl_event_loop(t_msdl *msdl, void *param);
void		msdl_poll_event(t_msdl *msdl, void *param, SDL_Event *event);
void		msdl_event_next(t_msdl *msdl, void *param, SDL_Event *event);
/*
** Don't need use msdl_event_next.
*/

void		msdl_end_loop(t_msdl *msdl);

/*
** Time stuff
*/

void		msdl_sleep(int millisecond);
/*
** This function use SDL_Delay, that is a function
** whose has some default. So, time of sleep can be longer
** than time wanted.
*/

unsigned int	msdl_get_time(void);

/*
** If Timer is on.
*/

void		msdl_add_timer(t_timer *timer, int period,
			       Uint32 (*fct_callback)(), void *param);
/*
** prototype of fct_callback is : Uint32 name_fct(Uint32 period, void *param);
** You must return period is your function callback.
*/

void		msdl_destroy_timer(t_timer *timer);

/*
** Music stuff
*/

int		msdl_music_init(int frequency);
void		msdl_save_music(t_music *music, char *name_music);
void		msdl_play_music(t_music *music, int loop);
void		msdl_cpy_music(t_music *dest, t_music *src);
void		msdl_destroy_music(t_music *music);
void		msdl_music_end(void);

/*
** Handles Music
*/

void		msdl_pause_music(void);
void		msdl_regain_music(void);
void		msdl_replay_music(void);
int		msdl_volume_music(unsigned int volume);
/*
** Volume is between O and 128. You can use MIX_MAX_VOLUME.
** return -1 if you try to give volume not between 0 to 128.
*/

void		msdl_stop_music(void);

int		msdl_playing_mode(void);
/*
** playing_mode return 1 if music is playing.
*/

int		msdl_paused_mode(void);
/*
** paused_mode return 1 if music is paused.
*/

/*
** Sound stuff
*/

void		msdl_alloc_channels(int nb_channels);
void		msdl_sound_init(t_sound *sound, char *name_sound);
int		msdl_volume_sound(t_sound *sound, unsigned int volume);
/*
** volume_sound have same behaviour of volume_music.
*/

void		msdl_play_sound(t_sound *sound, int period);
/*
** period is number of time + 1 !!!! You play sound.
*/

void		msdl_cpy_sound(t_sound *dest, t_sound *src);
void		msdl_destroy_sound(t_sound *sound);

/*
** ttf handles
*/

/*
** Return 0 if Success for init_ttf and prep_txt
*/
int		msdl_init_ttf(t_msdl *msdl, const char *font_name,
			      const unsigned int font_size,
			      const unsigned char style);
int		msdl_prep_txt(t_msdl *msdl, const char *txt,
			      int color, int color_shaded);
void		msdl_quit_ttf(t_msdl *msdl);
void		msdl_put_string(t_msdl *msdl, const int x, const int y);

/*
** Conversion int to string for put nbr.
*/
char		*msdl_init_string(int *nb, unsigned int *x,
				  unsigned int *d, int *s);
unsigned int	msdl_strlen(char *str, char *str2);
char		*msdl_concat_string(char *dec, char *rel,
				    const unsigned int size);

/*
** main function of convert.
*/
char		*msdl_int_to_char(int nb);
char		*msdl_double_to_char(double nb, unsigned int rel);

#endif /* !MINISDL_H_ */
