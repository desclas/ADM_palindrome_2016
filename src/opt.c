/*
** opt.c for  in /home/mathias/Bureau/projet_epitech/synthèse/ADM_palindrome_2016
** 
** Made by Mathias
** Login   <mathias.descoin@epitech.eu@epitech.net>
** 
** Started on  Thu Jun 15 17:00:57 2017 Mathias
** Last update Fri Jun 16 08:58:27 2017 Mathias
*/

#include "palin.h"

void error(void)
{
  printf("invalid argument\n");
  exit(84);
}

int check_opt(char *str)
{
  if (strcmp(str, "-n") == 0)
    return (N);
  else if (strcmp(str, "-p") == 0)
    return (P);
  else if (strcmp(str, "-b") == 0)
    return (B);
  else if (strcmp(str, "-imin") == 0)
    return (MIN);
  else if (strcmp(str, "-imax") == 0)
    return (MAX);
  else
    return (FAIL);
}

int check_error_opt(int *tab)
{
  if (tab[P] > 1 || tab[B] > 1 || tab[N] > 1 || tab[MIN] > 1 || tab[MAX] > 1)
    error();
  if ((tab[N] == 1 && tab[P] == 1) || (tab[MAX + 1] < tab[MIN + 1]) ||
      !(tab[B + 1] <= 10 && tab[B + 1] > 1) || tab[MIN + 1] < 0 ||
      tab[MAX + 1] < 0 || tab[N + 1] < 0 || tab[P + 1] < 0)
    error();
  return (0);
}

void choice(int *tab)
{
  int nb;
  char *str;

  nb = tab[MIN + 1];
  if (tab[N] == 1)
    {
      if ((str = find_palin(my_int_to_str_base(tab[N + 1], tab[B + 1]),
			    tab[B + 1], &nb, tab[MAX + 1])) == NULL)
	printf("no solution\n");
      else if (my_len(str) <= 32)
	{
	  printf("%d leads to %lld in %d iteration(s) in base %d\n",
		 tab[N + 1], my_base(str, tab[B + 1]), nb, tab[B + 1]);
	  free(str);
	}
    }
  else if (tab[P] == 1)
    all_palin(my_int_to_str_base(tab[P + 1], tab[B + 1]), tab[B + 1], tab[MIN + 1], tab[MAX + 1]);
}

void option(int av, char **ac)
{
  int i;
  int tab[10];
  int opt;

  initab(tab, 10);
  tab[B + 1] = 10;
  tab[MAX + 1] = 100;
  i = 1;
  while (i != av)
    {
      if ((opt = check_opt(ac[i])) != FAIL && check_opt(ac[i + 1]) == FAIL &&
	  is_int(ac[i + 1]) == 0)
	{
	  tab[opt] += 1;
	  tab[opt + 1] = atoi(ac[i + 1]);
	  i += 1;
	}
      else
	error();
      i += 1;
    }
  if (check_error_opt(tab) == 0)
    choice(tab);
}
