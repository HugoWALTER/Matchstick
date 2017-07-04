/*
** error_file.c for  in /home/walter_h/CPE_2016_matchstick
** 
** Made by Hugo WALTER
** Login   <walter_h@epitech.net>
** 
** Started on  Sat Feb 18 00:53:32 2017 Hugo WALTER
** Last update Wed Feb 22 11:25:05 2017 Hugo WALTER
*/

#include "my.h"

int     my_error(int ac, char **av)
{
  if (ac != 3)
    return (84);
  if (my_getnbr(av[1]) < 1 || my_getnbr(av[1]) > 100)
    return (84);
  return (0);
}

int     verif_letter(char *str)
{
  int   i;

  i = 0;
  while (str[i])
    {
      if (str[i] < '0' || str[i] > '9')
	return (84);
      if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
	return (84);
      i++;
    }
  i = 0;
  while (str[i])
    {
      if (str[i] < '0' || str[i] > '9')
	return (84);
      i++;
    }
  if (str[0] == '\0')
    return (84);
  return (0);
}

int     verif_line_error(char **av, char *s)
{
  if (verif_letter(s) == 84)
    my_putstr("Error: invalid input (positive number expected)\nLine: ");
  if (my_getnbr(s) == 0 && verif_letter(s) == 0)
    my_putstr("Error: this line is out of range\nLine: ");
  if (my_getnbr(s) > my_getnbr(av[1]) && verif_letter(s) == 0)
    my_putstr("Error: this line is out of range\nLine: ");
  return (0);
}

int     verif_matches_error2(char **av, char **tab, char *s, t_my_val *val)
{
  if (my_getnbr(s) > my_strlen(tab[val->nbline - 1]) && verif_letter(s) == 0)
    {
      my_putstr("Error: not enough matches on this line\nLine: ");
      return (42);
    }
  return (0);
}

int     verif_matches_error(char **av, char **tab, char *s, t_my_val *val)
{
  if (verif_letter(s) == 84)
    {
      my_putstr("Error: invalid input (positive number expected)\nLine: ");
      return (42);
    }
  if (my_getnbr(s) == 0 && verif_letter(s) == 0)
    {
      my_putstr("Error: you have to remove at least one match\nLine: ");
      return (42);
    }
  if (my_getnbr(s) < 0 && verif_letter(s) == 0)
    {
      my_putstr("Error: invalid input (positive number expected)\nLine: ");
      return (42);
    }
  if (my_getnbr(s) > my_getnbr(av[2]) && verif_letter(s) == 0)
    {
      my_printf("Error: you cannot remove more than %d matches\
 per turn\nLine: ", my_getnbr(av[2]));
      return (42);
    }
  if (verif_matches_error2(av, tab, s, val) == 42)
    return (42);
  return (0);
}
