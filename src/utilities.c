/*
** utilities.c for  in /home/mathias/Bureau/projet_epitech/synthèse/ADM_palindrome_2016
** 
** Made by Mathias
** Login   <mathias.descoin@epitech.eu@epitech.net>
** 
** Started on  Thu Jun 15 16:56:29 2017 Mathias
** Last update Thu Jun 15 16:58:00 2017 Mathias
*/

#include "palin.h"

int my_len(char *str)
{
  int i;

  i = 0;
  while (str[i] != '\0')
    i += 1;
  return (i);
}

void inistr(char *str, int max)
{
  int i;

  i = -1;
  while (++i != max)
    str[i] = '\0';
}

int is_int(char *str)
{
  int i;

  if (my_len(str) > 10)
    return (1);
  else if (my_len(str) == 10 && !(str[0] <= '2' && str[1] == 0))
    return (1);
  i = 1;
  while (str[i] != '\0')
    {
      if (!(str[i] <= 57 && str[i] >= 48))
	return (1);
      i += 1;
    }
  return (0);
}

char *append_char(char *str, char c)
{
  int i;
  char *res;

  res = malloc(sizeof(char) * (my_len(str) + 2));
  inistr(res, my_len(str) + 2);
  i = 0;
  while (str[i] != '\0')
    {
      res[i] = str[i];
      i += 1;
    }
  res[i] = c;
  free(str);
  return (res);
}

char *revstr_nofree(char *str)
{
  int i;
  int count;
  char *res;

  res = malloc(sizeof(char) * (my_len(str) + 2));
  inistr(res, my_len(str) + 2);
  i = -1;
  while (str[++i] != '\0');
  i -= 1;
  count = 0;
  while (i != -1)
    {
      res[count] = str[i];
      i -= 1;
      count += 1;
    }
  return (res);
}
