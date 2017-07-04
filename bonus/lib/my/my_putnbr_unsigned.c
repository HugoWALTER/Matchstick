/*
** my_putnbr_unsigned.c for my_putnbr_unsigned in /home/walter_h/PSU_2016_my_printf
** 
** Made by Hugo WALTER
** Login   <walter_h@epitech.net>
** 
** Started on  Thu Nov 17 10:40:17 2016 Hugo WALTER
** Last update Tue Nov 22 17:23:18 2016 Hugo WALTER
*/

#include "my.h"

unsigned int     my_putnbr_unsigned(unsigned int nb)
{
  unsigned int   dep;

  dep = 1;
  if (nb < 0)
    {
      return (0);
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
