/*
** my_putnbr_binary.c for my_putnbr_binary in /home/walter_h/PSU_2016_my_printf
** 
** Made by Hugo WALTER
** Login   <walter_h@epitech.net>
** 
** Started on  Mon Nov 14 09:16:46 2016 Hugo WALTER
** Last update Tue Nov 22 17:21:44 2016 Hugo WALTER
*/

#include "my.h"

unsigned int	my_putnbr_binary(unsigned int nbr)
{
  unsigned int	div;
  unsigned int	base_temp;
  unsigned int	res;
  char		*base;

  base = "01";
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
