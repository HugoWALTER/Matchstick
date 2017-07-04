/*
** my_strlen.c for my_strlen in /home/walter_h/CPool_Day04
** 
** Made by Hugo WALTER
** Login   <walter_h@epitech.net>
** 
** Started on  Thu Oct  6 17:37:13 2016 Hugo WALTER
** Last update Mon Oct 17 12:31:46 2016 Hugo WALTER
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}
