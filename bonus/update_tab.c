/*
** update_tab.c for update_tab in /home/walter_h/CPE_2016_matchstick
** 
** Made by Hugo WALTER
** Login   <walter_h@epitech.net>
** 
** Started on  Sat Feb 18 00:49:32 2017 Hugo WALTER
** Last update Sat Feb 18 22:17:36 2017 Hugo WALTER
*/

#include "my.h"

int     draw_contour_core(char **tab, int nb, int i, int space)
{
  int   k;

  my_putchar('*');
  k = 0;
  while (k != space)
    {
      my_putchar(' ');
      k++;
    }
  my_putstr(tab[i]);
  k = 0;
  while (k != space)
    {
      my_putchar(' ');
      k++;
    }
  my_putchar('*');
  return (0);
}

char    **draw_contour(char **tab, int nb, t_my_val *val)
{
  int   i;
  int   space;

  i = 0;
  space = nb - 1;
  my_putstr("  ");
  draw_extreme(nb);
  while (i != nb)
    {
      if (i <= 8)
	my_printf("%d ", i + 1);
      if (i >= 9)
	my_printf("%d", i + 1);
      draw_contour_core(tab, nb, i, space);
      space--;
      my_putchar('\n');
      i++;
    }
  my_putstr("  ");
  draw_extreme(nb);
  return (tab);
}

int     draw_updated_contour_core(t_my_val *val, int nb, int i, int space)
{
  int   k;

  my_putchar('*');
  k = 0;
  while (k != space)
    {
      my_putchar(' ');
      k++;
    }
  my_putstr(val->stock[i]);
  k = 0;
  while (k != space)
    {
      my_putchar(' ');
      k++;
    }
  my_putchar('*');
  return (0);
}

char    **draw_updated_contour(char **tab, int nb, t_my_val *val)
{
  int   i;
  int   space;

  i = 0;
  space = nb - 1;
  my_putstr("  ");
  draw_extreme(nb);
  while (i != nb)
    {
      if (i <= 8)
	my_printf("%d ", i + 1);
      if (i >= 9)
	my_printf("%d", i + 1);
      draw_updated_contour_core(val, nb, i, space);
      space--;
      my_putchar('\n');
      i++;
    }
  my_putstr("  ");
  draw_extreme(nb);
  return (tab);
}

char    **draw_stick(int nb, t_my_val *val)
{
  char  **tab;
  int   i;
  int   k;
  int   j;

  i = 0;
  k = 1;
  if ((tab = malloc(sizeof(char *) * nb + 1)) == NULL)
    return (NULL);
  while (i != nb)
    {
      j = 0;
      if ((tab[i] = malloc(sizeof(char) * nb * 2)) == NULL)
	return (NULL);
      while (j != k)
	{
	  tab[i][j] = '|';
	  j++;
	}
      i++;
      k += 2;
    }
  tab[j++] = NULL;
  val->nbstick = nb_stickmax(tab, val);
  return (tab);
}
