/*
** my_getnbr.c for my_getnbr in /home/walter_h/CPool_Day04
** 
** Made by Hugo WALTER
** Login   <walter_h@epitech.net>
** 
** Started on  Tue Oct 11 12:50:16 2016 Hugo WALTER
** Last update Mon Feb 13 11:44:18 2017 Hugo WALTER
*/

#include "my.h"

int	my_getnbr(char *str)
{
  int	res;
  int	sign;

  sign = 1;
  while (*str && (*str == '-' || *str == '+'))
    {
      if (*str == '-')
	sign = sign * -1;
      str++;
    }
  res = 0;
  while (*str && *str >= '0' && *str <= '9')
    res = res * 10 + (*str++ - '0');
  return (res * sign);
}
