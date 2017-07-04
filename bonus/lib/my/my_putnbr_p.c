/*
** my_putnbr_p.c for my_putnbr_p in /home/walter_h/PSU_2016_my_printf
** 
** Made by Hugo WALTER
** Login   <walter_h@epitech.net>
** 
** Started on  Thu Nov 17 16:06:34 2016 Hugo WALTER
** Last update Tue Nov 22 17:23:08 2016 Hugo WALTER
*/

#include "my.h"

long    my_putnbr_p(long nbr)
{
  long  div;
  long  base_temp;
  long  res;
  char          *base;

  base = "0123456789abcdef";
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
  return (nbr);
}
