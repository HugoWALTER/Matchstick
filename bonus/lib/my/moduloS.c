/*
** moduloS.c for moduloS in /home/walter_h/PSU_2016_my_printf
** 
** Made by Hugo WALTER
** Login   <walter_h@epitech.net>
** 
** Started on  Thu Nov 17 18:25:36 2016 Hugo WALTER
** Last update Tue Nov 22 17:20:47 2016 Hugo WALTER
*/

#include "my.h"

int	my_moduloS(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      while (str[i] >= 32 && str[i] < 127 && str[i] != '\0')
	{
	  my_putchar(str[i++]);
	}
      if ((str[i] < ' ' || str[i] == 127) && str[i] != '\0')
	{
	  my_putchar('\\');
	  if (str[i] <= 7)
	    my_putstr("00");
	  if (str[i] > 7 && str[i] < ' ')
	    my_putchar('0');
	  my_putnbr_octal(str[i]);
	  i++;
	}
    }
  return (0);
}
