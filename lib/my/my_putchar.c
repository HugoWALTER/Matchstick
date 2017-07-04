/*
** my_putchar.c for my_putchar in /home/walter_h/CPool_Day03
** 
** Made by Hugo WALTER
** Login   <walter_h@epitech.net>
** 
** Started on  Wed Oct  5 10:22:09 2016 Hugo WALTER
** Last update Mon Oct 17 11:41:10 2016 Hugo WALTER
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
