/*
** minisdl_macro.h for minisdl in /home/le-mai_s/librairie/minisdl1.x/include
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Fri Aug  7 10:31:48 2015 sebastien le-maire
** Last update Fri Aug 14 19:46:52 2015 sebastien le-maire
*/

#ifndef MINISDL_MACRO_H_
# define MINISDL_MACRO_H_

# include "minisdl_struct.h"

# define ALL_OFF 0
# define RESIZE_ON 1
# define TIMER_ON 2
# define RESIZE_TIMER_ON 3
# define FULLSCREEN_ON 4
# define TIMER_FULLSCREEN_ON 6
# define AUDIO_ON 8
# define RESIZE_AUDIO_ON 9
# define TIMER_AUDIO_ON 10
# define RESIZE_TIMER_AUDIO_ON 11
# define FULLSCREEN_AUDIO_ON 12
# define TIMER_FULLSCREEN_AUDIO_ON 14
# define OPENGL_ON 16
# define RESIZE_OPENGL_ON 17
# define TIMER_OPENGL_ON 18
# define RESIZE_TIMER_OPENGL_ON 19
# define FULLSCREEN_OPENGL_ON 20
# define TIMER_FULLSCREEN_OPENGL_ON 22
# define AUDIO_OPENGL_ON 24
# define RESIZE_AUDIO_OPENGL_ON 25
# define TIMER_AUDIO_OPENGL_ON 26
# define RESIZE_TIMER_AUDIO_OPENGL_ON 27
# define FULLSCREEN_AUDIO_OPENGL_ON 28
# define TIMER_FULLSCREEN_AUDIO_OPENGL_ON 30

# define CT1 (msdl->opt_win == TIMER_ON)
# define CT2 (msdl->opt_win == RESIZE_TIMER_ON)
# define CT3 (msdl->opt_win == TIMER_FULLSCREEN_ON)

# define CA1 (msdl->opt_win == AUDIO_ON)
# define CA2 (msdl->opt_win == RESIZE_AUDIO_ON)
# define CA3 (msdl->opt_win == FULLSCREEN_AUDIO_ON)


# define CTA1 (msdl->opt_win == TIMER_AUDIO_ON)
# define CTA2 (msdl->opt_win == RESIZE_TIMER_AUDIO_ON)
# define CTA3 (msdl->opt_win == TIMER_FULLSCREEN_AUDIO_ON)

# define CVONLY1 (msdl->opt_win == ALL_OFF)
# define CVONLY2 (msdl->opt_win == RESIZE_ON)
# define CVONLY3 (msdl->opt_win == FULLSCREEN_ON)

# define CO1 (msdl->opt_win == OPENGL_ON)
# define CO2 (msdl->opt_win == RESIZE_OPENGL_ON)
# define CO3 (msdl->opt_win == FULLSCREEN_OPENGL_ON)

# define CTO1 (msdl->opt_win == TIMER_OPENGL_ON)
# define CTO2 (msdl->opt_win == RESIZE_TIMER_OPENGL_ON)
# define CTO3 (msdl->opt_win == TIMER_FULLSCREEN_OPENGL_ON)

# define CAO1 (msdl->opt_win == AUDIO_OPENGL_ON)
# define CAO2 (msdl->opt_win == RESIZE_AUDIO_OPENGL_ON)
# define CAO3 (msdl->opt_win == FULLSCREEN_AUDIO_OPENGL_ON)

# define CTAO1 (msdl->opt_win == TIMER_AUDIO_OPENGL_ON)
# define CTAO2 (msdl->opt_win == RESIZE_TIMER_AUDIO_OPENGL_ON)
# define CTAO3 (msdl->opt_win == TIMER_FULLSCREEN_AUDIO_OPENGL_ON)

# define POS (x + (y *( msdl->scrn->w)))

/*
** Use in msdl_audio_init. You can use MIX_DEFAULT_FREQUENCY
*/
# define CD_QUALITY 44100

/*
** Use in msdl_play_music and msdl_play_sound.
*/
# define AUDIO_LOOP_INF (-1)

# define RGB(r, g, b) (((r) << 16) | ((g) << 8) | (b))

/*
** Permit to give event to left shift + every key on the keyboard.
*/
# define COND_SIMULT_KEY_LSHIFT ((mode & KMOD_LSHIFT) == KMOD_LSHIFT)

/*
** differents types of font.
*/
# define SOLID (0)
# define BLENDED (1)
# define SHADED (2)

#endif /* !MINISDL_MACRO_H_ */
