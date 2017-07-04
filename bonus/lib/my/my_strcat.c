/*
** my_strcat.c for my_strcat in /home/walter_h/CPool_Day07
** 
** Made by Hugo WALTER
** Login   <walter_h@epitech.net>
** 
** Started on  Tue Oct 11 16:54:03 2016 Hugo WALTER
** Last update Wed Dec 14 20:26:39 2016 Hugo WALTER
*/

#include "my.h"

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;

  i = 0;
  j = my_strlen(dest);
  while (src[i] != '\0')
    {
      dest[j + i] = src[i];
      i++;
    }
  dest[j + i] = '\0';
  return (dest);
}
