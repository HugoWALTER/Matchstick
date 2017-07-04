/*
** get_next_line.c for get_next_line in /home/walter_h/gnlfork
** 
** Made by Hugo WALTER
** Login   <walter_h@epitech.net>
** 
** Started on  Fri Jan 13 15:45:11 2017 Hugo WALTER
** Last update Sat Feb 18 01:37:10 2017 Hugo WALTER
*/

#include "my.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

char	get_first_line(const int fd)
{
  static char	*buffer;
  static int	i = 0;
  static int	valread = 0;
  char		line;

  if ((buffer = malloc(sizeof(*buffer) * (READ_SIZE))) == NULL)
    return ('\0');
  if (valread == 0)
    {
      i = 0;
      if ((valread = read(fd, buffer, READ_SIZE)) <= 0)
	return ('\0');
      if (valread == 0)
	return ('\0');
    }
  line = buffer[i];
  i++;
  valread--;
  return (line);
}

char	*my_realloc(char *buffer, int sizeline)
{
  char	*line;
  int	i;
  int	j;

  i = 0;
  j = 0;
  line = buffer;
  buffer = malloc(sizeof(int) * (READ_SIZE + sizeline));
  if (buffer == NULL)
    return (NULL);
  while (line[i] != '\0')
    buffer[j++] = line[i++];
  buffer[j] = '\0';
  return (buffer);
}

char	*check_end(char *buffer, char line, int i)
{
  if (line == '\0' && buffer[0] == '\0')
    return (NULL);
  buffer[i] = '\0';
  return (buffer);
}

char	*check_for_realloc(const int fd, char *buffer, char line, int i)
{
  while (line != '\n' && line != '\0')
    {
      buffer[i] = line;
      line = get_first_line(fd);
      i++;
      if ((buffer[i] % READ_SIZE) == 0)
	{
	  buffer[i] = '\0';
	  buffer = my_realloc(buffer, (READ_SIZE + i));
	}
    }
  return (check_end(buffer, line, i));
}

char	*get_next_line(const int fd)
{
  char	*buffer;
  char	line;
  int	i;

  i = 0;
  if ((buffer = malloc(sizeof(*buffer) * READ_SIZE + 1)) == NULL)
    return (NULL);
  buffer[0] = '\0';
  line = '\0';
  line = get_first_line(fd);
  return (check_for_realloc(fd, buffer, line, i));
}
