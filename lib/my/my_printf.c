/*
** my_printf.c for my_printf in /home/walter_h/PSU_2016_my_printf
** 
** Made by Hugo WALTER
** Login   <walter_h@epitech.net>
** 
** Started on  Sun Nov 13 14:05:46 2016 Hugo WALTER
** Last update Thu Jan 19 18:22:11 2017 Hugo WALTER
*/

#include "my.h"

void    my_modulo2(const char *format, int i , va_list ap)
{
  int	d;

  d = 0;
  if (format[i + 1] == 'x')
    my_putnbr_hexmin(d + va_arg(ap, unsigned int));
  if (format[i + 1] == 'X')
    my_putnbr_hexmax(d + va_arg(ap, unsigned int));
}

void	my_modulo(const char *format, int i, va_list ap)
{
  int	d;

  d = 0;
  if (format[i + 1] == 'c')
      my_putchar(d + (char) va_arg(ap, int));
  if (format[i + 1] == 'd' || format[i + 1] == 'i')
    my_put_nbr(d + va_arg(ap, int));
  if (format[i + 1] == 'o')
    my_putnbr_octal(d + va_arg(ap, unsigned int));
  if (format[i + 1] == 'u')
    my_putnbr_unsigned(d + va_arg(ap, unsigned int));
  if (format[i + 1] == 's')
    my_putstr(d + va_arg(ap, char *));
  if (format[i + 1] == 'b')
    my_putnbr_binary(d + va_arg(ap, unsigned int));
  if (format[i + 1] == 'p')
    {
      my_putstr("0x");
      my_putnbr_p(d + va_arg(ap, long));
    }
  if (format[i + 1] == 'S')
    my_moduloS(d + va_arg(ap, char *));
}

void    my_test(const char *format, int i , va_list ap)
{
  int	d;

  d = 0;
  if (format[i] == '%' && format[i + 1] == '#' && format[i + 2] != '%')
    {
      if (format[i] == '%' && format[i + 1] == '#' && format[i + 2] == 'o')
	{
	  my_putchar('0');
	  my_putnbr_octal(d + va_arg(ap, unsigned int));
	}
    }
}

int	my_search(char s)
{
  char	*str;
  int	i;

  i = 0;
  str = my_strdup("cdiousbpSxX");
  while (str[i] != '\0')
    {
      if (s == str[i])
	return (0);
      i++;
    }
  return (42);
}

int	my_printf(const char *format, ...)
{
  va_list	ap;
  int		i;

  va_start(ap, format);
  i = 0;
  while (format[i] != '\0')
    {
      if (format[i] == '%' && (my_search(format[i + 1]) != 42))
	{
	  my_test(format, i, ap);
	  my_modulo(format, i, ap);
	  my_modulo2(format, i, ap);
	  i++;
	}
      else
	i = affichage(format, i);
      i++;
    }
  va_end(ap);
  return (0);
}
