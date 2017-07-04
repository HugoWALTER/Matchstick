/*
** my_strcpy.c for my_strcpy in /home/walter_h/CPool_Day06
** 
** Made by Hugo WALTER
** Login   <walter_h@epitech.net>
** 
** Started on  Mon Oct 10 08:51:58 2016 Hugo WALTER
** Last update Thu Jan 19 18:19:36 2017 Hugo WALTER
*/

#include "my.h"

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  return (dest);
}
