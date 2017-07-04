/*
** my_putstr.c for my_putstr in /home/walter_h/CPool_Day04
** 
** Made by Hugo WALTER
** Login   <walter_h@epitech.net>
** 
** Started on  Thu Oct  6 15:50:01 2016 Hugo WALTER
** Last update Tue Jan 24 09:44:43 2017 Hugo WALTER
*/

#include "my.h"

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
  return (0);
}
