/*
** debug.h for tetris in /home/detroy_j/Documents/delivery/tetris/include
** 
** Made by detroy_j
** Login   <jean-baptiste.detroyes@epitech.eu@epitech.net>
** 
** Started on  Mon Feb 20 14:51:00 2017 detroy_j
** Last update Mon Feb 20 18:31:31 2017 detroy_j
*/

#ifndef _OPTIONS_
# define _OPTIONS_

# define OPT_KEY_LEFT "-key-left"
# define OPT_KEY_RIGHT "-key-right"
# define OPT_KEY_TOP "-key-top"
# define OPT_KEY_DROP "-key-drop"
# define OPT_KEY_PAUSE "-key-pause"
# define OPT_KEY_QUIT "-key-quit"
# define OPT_SIZE = "-map-size"
# define OPT_WITHOUT = "-without-next"
# define OPT_DEBUG = "-debug"

typedef struct s_options t_options;
struct s_options
{
  int	level;
  int	k_left;
  int	k_right;
  int	k_top;
  int	k_drop;
  int	k_quit;
  int	k_pause;
  int	map_size_col;
  int	map_size_row;
  short	without_next;
  short	debug;
};

/*
** Init 
*/
t_options       *init_options();

/*
** Misc
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

/*
** Set options
*/
void    set_start_level(t_options *opts, char *value);
void    set_key_left(t_options *opts, char *value);
void    set_key_right(t_options *opts, char *value);
void    set_key_drop(t_options *opts, char *value);
void    set_key_top(t_options *opts, char *value);
void    set_key_quit(t_options *opts, char *value);
void    set_key_pause(t_options *opts, char *value);
void    set_map_size(t_options *opts, char *value);

/*
** Error handling
*/
void    check_error_key(t_options *opts);
int     is_double_key(t_options *opts, int key);

/*
** Debug
*/
void    show_debug(t_options *opts);

# endif
