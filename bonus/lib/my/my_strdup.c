/*
** my_strdup.c for my_strdup in /home/walter_h/CPool_Day08/task01
** 
** Made by Hugo WALTER
** Login   <walter_h@epitech.net>
** 
** Started on  Wed Oct 12 11:30:30 2016 Hugo WALTER
** Last update Tue Nov 22 18:42:49 2016 Hugo WALTER
*/

#include "my.h"

char	*my_strdup(char *str)
{
  char	*s;

  if ((s = malloc(my_strlen(str))) == 0)
    {
      return (0);
    }
  my_strcpy(s, str);
  return (s);
}
