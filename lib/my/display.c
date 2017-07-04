/*
** display.c for display in /home/walter_h/PSU_2016_my_printf/lib/my
** 
** Made by Hugo WALTER
** Login   <walter_h@epitech.net>
** 
** Started on  Tue Nov 22 18:54:07 2016 Hugo WALTER
** Last update Tue Nov 22 21:16:44 2016 Hugo WALTER
*/

#include "my.h"

int     affichage(const char *format, int i)
{
  if (format[i] == '%' && format[i + 1] != '%')
    {
      my_putchar(format[i]);
      my_putchar(format[i + 1]);
      i++;
    }
  else
    {
      if (format[i] == '%' && format[i + 1] == '%')
	{
	  my_putchar(format[i]);
	  i++;
	}
      else
	my_putchar(format[i]);
    }
  return (i);
}
