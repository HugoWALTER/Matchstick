/*
** my_putnbr_base.c for my_putnbr_base in /home/walter_h/CPool_Day06
** 
** Made by Hugo WALTER
** Login   <walter_h@epitech.net>
** 
** Started on  Tue Oct 11 13:42:34 2016 Hugo WALTER
** Last update Thu Jan 19 18:20:39 2017 Hugo WALTER
*/

#include "my.h"

int	my_putnbr_base(int nbr, char *base)
{
  int	div;
  int	base_temp;
  int	res;

  base_temp = my_strlen(base);
  if (nbr < 0)
    {
      my_putchar('-');
      nbr = -(nbr);
    }
  div = 1;
  while ((nbr / div) >= base_temp)
    div = div * base_temp;
  while (div > 0)
    {
      res = (nbr / div) % base_temp;
      my_putchar(base[res]);
      div = div / base_temp;
    }
  return (0);
}
