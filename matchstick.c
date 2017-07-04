/*
** matchstick.c for matchstick in /home/walter_h/CPE_2016_matchstick
** 
** Made by Hugo WALTER
** Login   <walter_h@epitech.net>
** 
** Started on  Mon Feb 13 11:34:49 2017 Hugo WALTER
** Last update Wed Feb 22 11:11:00 2017 Hugo WALTER
*/

#include "my.h"

char	**remove_stick(char **tab, t_my_val *val, char **av)
{
  int	i;
  int	j;
  int	k;
  int	l;

  i = val->nbline - 1;
  k = val->nbmatches;
  j = 0;
  l = k;
  while (j < k)
    {
      if (tab[i][my_strlen(tab[i]) - l] == '|')
	tab[i][my_strlen(tab[i]) - l] = ' ';
      if (val->stock[i][my_strlen(tab[i]) - l] == '|')
	val->stock[i][my_strlen(tab[i]) - l] = ' ';
      l--;
      j++;
    }
  tab[i][my_strlen(tab[i]) - k] = '\0';
  val->stock[i][my_strlen(tab[i])] = ' ';
  val->nbstick = val->nbstick - val->nbmatches;
  return (tab);
}

char	**player_and_ia(char **tab, char **av, t_my_val *val, char *s)
{
  if (my_getnbr(s) >= 1 && my_getnbr(s) <= my_getnbr(av[2]) &&
      verif_letter(s) == 0)
    {
      val->nbmatches = my_getnbr(s);
      tab = remove_stick(tab, val, av);
      my_printf("Player removed %d match(es) from line %d\n",
	     val->nbmatches, val->nbline);
      val->stock = draw_updated_contour(val->stock, my_getnbr(av[1]), val);
      if (check_win_player(val) == 1)
	return (NULL);
      my_putchar('\n');
      tab = ia_turn(tab, av, val);
      if (check_win_ia(val) == 2)
	return (NULL);
      my_putchar('\n');
      my_putstr("Your turn:\nLine: ");
    }
  return (tab);
}

char	**player_turn(char **tab, char **av, t_my_val *val)
{
  char	*s;

  my_putstr("Your turn:\nLine: ");
  while ((s = get_next_line(0)))
    {
      verif_line_error(av, s);
      if (my_getnbr(s) >= 1 && my_getnbr(s) <= my_getnbr(av[1])
	  && verif_letter(s) == 0)
	{
	  val->nbline = my_getnbr(s);
	  free(s);
	  my_putstr("Matches: ");
	  while ((s = get_next_line(0)))
	    {
	      if (verif_matches_error(av, tab, s, val) == 42)
		break ;
	      if ((tab = player_and_ia(tab, av, val, s)) == NULL)
		return (NULL);
	      break ;
	    }
	}
    }
  return (NULL);
}

int	val_return(t_my_val *val)
{
  if (val->winplayer == 1)
    {
      my_printf("You lost, too bad...\n");
      return (2);
    }
  if (val->winia == 2)
    {
      my_printf("I lost... snif... but I'll get you next time!!\n");
      return (1);
    }
  return (0);
}

int	main(int ac, char **av)
{
  char		**tab;
  t_my_val	*val;

  if (my_error(ac, av) == 84)
    return (84);
  init_struct(&val);
  val->stock = draw_stick(my_getnbr(av[1]), val);
  tab = draw_stick(my_getnbr(av[1]), val);
  tab = draw_contour(tab, my_getnbr(av[1]), val);
  my_putchar('\n');
  while (val->winplayer != 1 || val->winia != 2)
    if (player_turn(tab, av, val) == NULL)
      return (val_return(val));
  return (0);
}
