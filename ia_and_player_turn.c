/*
** ia_and_player_turn.c for ia_and_player_turn in /home/walter_h/CPE_2016_matchstick
** 
** Made by Hugo WALTER
** Login   <walter_h@epitech.net>
** 
** Started on  Sat Feb 18 00:56:54 2017 Hugo WALTER
** Last update Mon Feb 20 09:53:11 2017 Hugo WALTER
*/

#include "my.h"

int     check_win_player(t_my_val *val)
{
  if (val->nbstick == 0)
    {
      val->winplayer = 1;
      return (1);
    }
  return (0);
}

int     check_win_ia(t_my_val *val)
{
  if (val->nbstick == 0)
    {
      val->winia = 2;
      return (2);
    }
  return (0);
}

void    ia_line(char **tab, char **av, t_my_val *val)
{
  int   i;

  i = (rand() * (my_getnbr(av[1]) + 1) / RAND_MAX + 1);
  if (my_strlen(tab[i - 1]) == 0)
    {
      while (my_strlen(tab[i - 1]) == 0)
	i++;
    }
  if (i > my_getnbr(av[1]))
    i = my_getnbr(av[1]);
  if (my_strlen(tab[i - 1]) != 0)
    val->nbline = (rand() * (my_getnbr(av[1]) + 1 - i) / RAND_MAX + i);
}

void    ia_matches(char **tab, char **av, t_my_val *val)
{
  if (my_strlen(tab[val->nbline - 1]) > my_getnbr(av[2]))
    val->nbmatches = my_getnbr(av[2]) - 1;
  if (my_strlen(tab[val->nbline - 1]) < my_getnbr(av[2]) &&
      my_strlen(tab[val->nbline - 1]) > 1)
    val->nbmatches = (rand() * (my_getnbr(av[2]) + 1 - 1) / RAND_MAX + 1);
  if (my_strlen(tab[val->nbline - 1]) == 1)
    val->nbmatches = 1;
  if (my_strlen(tab[val->nbline - 1]) == 3)
    val->nbmatches = 2;
}

char    **ia_turn(char **tab, char **av, t_my_val *val)
{
  my_printf("AI's turn...\n");
  srand(time(NULL));
  ia_line(tab, av, val);
  ia_matches(tab, av, val);
  tab = remove_stick(tab, val, av);
  my_printf("AI removed %d match(es) from line %d\n", val->nbmatches,
	 val->nbline);
  val->stock = draw_updated_contour(val->stock, my_getnbr(av[1]), val);
  return (tab);
}
