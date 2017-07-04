/*
** my_strcmp.c for my_strcmp in /home/walter_h/CPool_Day06
** 
** Made by Hugo WALTER
** Login   <walter_h@epitech.net>
** 
** Started on  Mon Oct 10 15:09:46 2016 Hugo WALTER
** Last update Fri Jan 20 10:00:34 2017 Hugo WALTER
*/

#include <string.h>
#include "my.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (s1[i] != '\0' && s2[i] != '\0')
    {
      if (s1[i] == s2[i])
	j = j + 0;
      if (s1[i] != s2[i])
	j = j + 1;
      i = i + 1;
    }
  return (j);
}
