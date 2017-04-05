/*
** debug.h for tetris in /home/detroy_j/Documents/delivery/tetris/include
** 
** Made by detroy_j
** Login   <jean-baptiste.detroyes@epitech.eu@epitech.net>
** 
** Started on  Mon Feb 20 14:51:00 2017 detroy_j
** Last update Sun Mar 19 16:05:44 2017 detroy_j
*/

#include "tetriminos.h"

#ifndef _OPTIONS_
# define _OPTIONS_

/*
** Options shortcuts arguments
*/
# define SOPT_LEVEL "-l"
# define SOPT_KEY_LEFT "-kl"
# define SOPT_KEY_RIGHT "-kr"
# define SOPT_KEY_TURN "-kt"
# define SOPT_KEY_DROP "-kd"
# define SOPT_KEY_PAUSE "-kp"
# define SOPT_KEY_QUIT "-kq"
# define SOPT_WITHOUT "-w"
# define SOPT_DEBUG "-d"

/*
** Options arguments
*/
# define OPT_LEVEL "--level"
# define OPT_KEY_LEFT "--key-left"
# define OPT_KEY_RIGHT "--key-right"
# define OPT_KEY_TURN "--key-turn"
# define OPT_KEY_DROP "--key-drop"
# define OPT_KEY_PAUSE "--key-pause"
# define OPT_KEY_QUIT "--key-quit"
# define OPT_SIZE "--map-size"
# define OPT_WITHOUT "--without-next"
# define OPT_DEBUG "--debug"

/*
** Options default arguments
*/
# define DEFAULT_LEVEL (1)
# define DEFAULT_KEY_QUIT "q"
# define DEFAULT_KEY_PAUSE " "
# define DEFAULT_ROW (20)
# define DEFAULT_COL (10)
# define DEFAULT_WITHOUT (0)
# define DEFAULT_DEBUG (0)

/*
** Keys name
*/
# define _KEY_SPACE "(space)"
# define _KEY_LEFT "^EOD"
# define _KEY_RIGHT "^EOC"
# define _KEY_UP "^EOE"
# define _KEY_DOWN "^EOV"

typedef struct s_options t_options;
struct s_options
{
  int	level;
  char	*k_left;
  char	*k_right;
  char	*k_turn;
  char	*k_drop;
  char	*k_quit;
  char	*k_pause;
  int	k_defined[6];
  int	map_size_col;
  int	map_size_row;
  short	without_next;
  short	debug;
  char	*bin_name;
};

/*
** Init
*/
t_options       *init_options();

/*
** Miscs
*/
int     is_number(const char *str);
int     have_comma(const char *str);
int     have_equal(const char *str);
void    my_putstr_error(const char *s);

/*
** Get options
*/
void    get_arguments(t_options *opts, int ac, char **av);
void    get_option(t_options *opts, char *name, char *value);
char    *get_no_display_key(char *str);

/*
** Set options
*/
void    set_start_level(t_options *opts, char *value);
void    set_key_left(t_options *opts, char *value);
void    set_key_right(t_options *opts, char *value);
void    set_key_drop(t_options *opts, char *value);
void    set_key_turn(t_options *opts, char *value);
void    set_key_quit(t_options *opts, char *value);
void    set_key_pause(t_options *opts, char *value);
void    set_map_size(t_options *opts, char *value);

/*
** Error handling
*/
void    check_error_key(t_options *opts);

/*
** Debug & Help
*/
void    show_debug(t_g *game, t_options *opts);
void	show_help(t_options *opts, int i);

/*
** Free
*/
void    my_free_options(t_options *opts);

# endif
