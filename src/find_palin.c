/*
** find_palin.c for  in /home/mathias/Bureau/projet_epitech/synthèse/ADM_palindrome_2016
** 
** Made by Mathias
** Login   <mathias.descoin@epitech.eu@epitech.net>
** 
** Started on  Thu Jun 15 16:58:34 2017 Mathias
** Last update Fri Jun 16 10:50:42 2017 Mathias
*/

#include "palin.h"

char *revstr(char *str)
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
  free(str);
  return (res);
}

char *my_int_to_str_base(int nb, int base)
{
  char *str;

  str = malloc(sizeof(char) * 2);
  inistr(str, 2);
  if (nb == 0)
    str[0] = '0';
  while (nb != 0)
    {
      str = append_char(str, (nb % base) + 48);
      nb -= (nb % base);
      nb /= base;
    }
  return (revstr(str));
}

char *str_add(char *nb, char *bn, int base)
{
  char *str;
  int rem;
  int i;

  i = -1;
  rem = 0;
  str = malloc(sizeof(char));
  str[0] = '\0';
  while (nb[++i] != '\0')
    if ((nb[i] + bn[i] - 96) + rem > base - 1)
      {
	str = append_char(str, ((nb[i] + bn[i] - 96 + rem) % base) + 48);
	rem = 1;
      }
    else
      {
	str = append_char(str, (nb[i] + bn[i] - 96) + rem + 48);
	rem = 0;
      }
  if (rem == 1)
    str = append_char(str, '1');
  free(nb);
  free(bn);
  return (revstr(str));
}

int is_palin(char *str)
{
  int i;
  int len;

  i = -1;
  len = my_len(str) - 1;
  while (str[++i] != '\0')
    if (str[i] != str[len - i])
      return (1);
  return (0);
}

char *find_palin(char *nb, int base, int *min, int max)
{
  int i;

  i = -1;
  while (++i != *min)
    nb = str_add(nb, revstr_nofree(nb), base);
  if (is_palin(nb) == 0)
    return (nb);
  while (i != max + 1)
    {
      if (is_palin(nb) == 0)
	return (nb);
      nb = str_add(nb, revstr_nofree(nb), base);
      i += 1;
      *min = i;
    }
  free(nb);
  return (NULL);
}
