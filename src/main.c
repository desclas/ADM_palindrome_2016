/*
** test.c for  in /home/mathias/Bureau/projet_epitech/synthèse/ADM_palindrome_2016
** 
** Made by Mathias
** Login   <mathias.descoin@epitech.eu@epitech.net>
** 
** Started on  Thu Jun 15 11:48:33 2017 Mathias
** Last update Fri Jun 16 09:16:25 2017 Mathias
*/

#include "palin.h"

void error_all_palin(char *str, char *nb)
{
  free(str);
  free(nb);
  printf("no solution\n");
  exit(84);
}

long long int my_base(char *str, int base)
{
  long long int res;
  int i;
  int pw;

  pw = 0;
  i = my_len(str) - 1;
  res = 0;
  while (i != -1)
    {
      res += (str[i] - 48) * pow(base, pw);
      i -= 1;
      pw += 1;
    }
  return (res);
}

void initab(int *tab, int max)
{
  int i;

  i = 0;
  while (i != max)
    {
      tab[i] = 0;
      i += 1;
    }
}

int main(int av, char **ac)
{
  if (av > 1 && av % 2 == 1)
    option(av, ac);
  else if (av > 1 && strcmp(ac[1], "-h") == 0)
    printf("no help\n");
  else
    error();
  return (0);
}
