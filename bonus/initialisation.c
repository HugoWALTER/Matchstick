/*
** initialisation.c for initialisation in /home/walter_h/CPE_2016_matchstick
** 
** Made by Hugo WALTER
** Login   <walter_h@epitech.net>
** 
** Started on  Sat Feb 18 00:47:24 2017 Hugo WALTER
** Last update Sat Feb 18 16:15:48 2017 Hugo WALTER
*/

#include "my.h"

void    init_struct(t_my_val **val)
{
  t_my_val      *lm;

  if ((lm = malloc(sizeof(*lm))) == NULL)
    return ;
  lm->nbstick = 0;
  lm->nbline = 0;
  lm->nbmatches = 0;
  lm->winplayer = 0;
  lm->winia = 0;
  *val = lm;
}

int     draw_extreme(int nbdep)
{
  int   i;

  i = 0;
  while (i != ((nbdep * 2) + 1))
    {
      my_putchar('*');
      i++;
    }
  my_putchar('\n');
  return (0);
}

int     my_strlenstick(char *str)
{
  int   i;

  i = 0;
  while (str[i] && str[i] != ' ')
    i++;
  return (i);
}

int     nb_stickmax(char **tab, t_my_val *val)
{
  int   i;
  int   nbstick;

  nbstick = 0;
  i = 0;
  while (tab[i])
    {
      nbstick = nbstick + my_strlenstick(tab[i]);
      i++;
    }
  return (nbstick);
}

void    afftab(char **tab)
{
  int   i;

  i = 0;
  while (tab[i])
    {
      my_printf("%s\n", tab[i]);
      i++;
    }
}
