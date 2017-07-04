/*
** my_put_nbr.c for my_put_nbr in /home/walter_h/CPool_Day03
** 
** Made by Hugo WALTER
** Login   <walter_h@epitech.net>
** 
** Started on  Wed Oct  5 23:53:23 2016 Hugo WALTER
** Last update Tue Nov 22 17:29:29 2016 Hugo WALTER
*/

#include "my.h"

int	my_put_nbr(int nb)
{
  int	dep;

  dep = 1;
  if (nb == -2147483648)
    {
      my_putchar('-');
      my_putchar('2');
      nb = 147483648;
    }
  if (nb < 0)
    {
      my_putchar('-');
      nb = (nb * (-1));
    }
  while ((nb / dep) >= 10)
    {
      dep = dep * 10;
    }
  while (dep > 0)
    {
      my_putchar('0' + (nb / dep) % 10);
      dep = dep / 10;
    }
  return (nb);
}
