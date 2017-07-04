/*
** my.h for my.h in /home/walter_h/PSU_2016_minishell1/include
** 
** Made by Hugo WALTER
** Login   <walter_h@epitech.net>
** 
** Started on  Thu Jan 19 17:29:45 2017 Hugo WALTER
** Last update Sat Feb 18 01:30:12 2017 Hugo WALTER
*/

#ifndef MY_H
# define MY_H
# define READ_SIZE 1

#include <time.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct  s_my_val
{
  int   nbstick;
  int	nbline;
  int	nbmatches;
  char	**stock;
  int	winplayer;
  int	winia;
}               t_my_val;

int		my_putchar(char);
int		my_putstr(char *str);
int		my_put_nbr(int);
int		my_strlen(char *);
int		my_getnbr(char *);
int		my_search(char s);
int		my_putnbr_base(int nbr, char *base);
int		my_strcmp(char *s1, char *s2);
unsigned int	my_putnbr_binary(unsigned int nbr);
unsigned int	my_putnbr_hexmin(unsigned int nbr);
unsigned int	my_putnbr_hexmax(unsigned int nbr);
unsigned int	my_putnbr_octal(unsigned int nbr);
unsigned int	my_putnbr_unsigned(unsigned int nb);
long		my_putnbr_p(long nbr);
int		my_moduloS(char *str);
char		*my_strdup(char *str);
int		my_putnbr_octalint(int nbr);
int		my_printf(const char *format, ...);
void		my_modulo(const char *format, int i , va_list ap);
void		my_modulo2(const char *format, int i , va_list ap);
void		my_test(const char *format, int i , va_list ap);
void		modulomodulo(const char *format, int i);
int		affichage(const char *format, int i);
char		get_first_line(const int fd);
char		*my_realloc(char *buffer, int sizeline);
char		*check_end(char *buffer, char line, int i);
char		*check_for_realloc(const int fd, char *buffer,
				   char line, int i);
char		*get_next_line(const int fd);
char		*my_strcat(char *dest, char *src);
char		*my_strcpy(char *dest, char *src);
int		main(int ac, char **av);
int		my_error(int ac, char **av);
int		verif_letter(char *str);
int		verif_line_error(char **av, char *s);
int		verif_matches_error2(char **av, char **tab, char *s,
				     t_my_val *val);
int		verif_matches_error(char **av, char **tab, char *s,
				    t_my_val *val);
int		check_win_player(t_my_val *val);
int		check_win_ia(t_my_val *val);
void		ia_line(char **tab, char **av, t_my_val *val);
void		ia_matches(char **tab, char **av, t_my_val *val);
char		**ia_turn(char **tab, char **av, t_my_val *val);
void		init_struct(t_my_val **val);
int		draw_extreme(int nbdep);
int		my_strlenstick(char *str);
int		nb_stickmax(char **tab, t_my_val *val);
void		afftab(char **tab);
char		**remove_stick(char **tab, t_my_val *val, char **av);
char		**player_and_ia(char **tab, char **av, t_my_val *val,
				char *s);
char		**player_turn(char **tab, char **av, t_my_val *val);
int		val_return(t_my_val *val);
int		draw_contour_core(char **tab, int nb, int i, int space);
char		**draw_contour(char **tab, int nb, t_my_val *val);
int		draw_updated_contour_core(t_my_val *val, int nb, int i,
					  int space);
char		**draw_updated_contour(char **tab, int nb, t_my_val *val);
char		**draw_stick(int nb, t_my_val *val);

#endif /* !MY_H */
