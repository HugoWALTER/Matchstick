/*
** my_putnbr_octalint.c for my_putnbr_octalint in /home/walter_h/PSU_2016_my_printf
** 
** Made by Hugo WALTER
** Login   <walter_h@epitech.net>
** 
** Started on  Thu Nov 17 23:42:08 2016 Hugo WALTER
** Last update Tue Nov 22 17:22:55 2016 Hugo WALTER
*/

#include "my.h"

int    my_putnbr_octalint(int nbr)
{
  int  div;
  int  base_temp;
  int  res;
  char          *base;

  base = "01234567";
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
