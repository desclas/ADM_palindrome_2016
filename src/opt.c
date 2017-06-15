/*
** opt.c for  in /home/mathias/Bureau/projet_epitech/synthèse/ADM_palindrome_2016
** 
** Made by Mathias
** Login   <mathias.descoin@epitech.eu@epitech.net>
** 
** Started on  Thu Jun 15 17:00:57 2017 Mathias
** Last update Thu Jun 15 19:03:21 2017 Mathias
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
      !(tab[B + 1] <= 10 && tab[B + 1] > 1))
    error();
  return (0);
}

int check_nb(char *nb, char *str)
{
  int i;

  if (my_len(nb) > my_len(str))
    return (LOW);
  else if (my_len(nb) < my_len(str))
    return (HIGH);
  else
    {
      i = 0;
      while (nb[i] != '\0')
	{
	  if (nb[i] < str[i])
	    return (HIGH);
	  else if (nb[i] > str[i])
	    return (LOW);
	  i += 1;
	}
      return (OK);
    }
}

char *add_one(char *str, int base)
{
  int i;

  i = 0;
  str[0] += 1;
  while (str[i] > (base + 47))
    {
      str[i] = '0';
      i += 1;
      if (str[i] == '\0')
	str = append_char(str, '1');
      else
	str[i] += 1;
    }
  return (revstr(str));
}

char *have_palin(char *str, char *nb, int base, int *tab)
{
  int i;

  i = -1;
  while (++i != tab[0])
    str = str_add(str, revstr_nofree(str), base);
  while (i != tab[1] && check_nb(nb, str) != HIGH)
    {
      if (check_nb(nb, str) == OK)
	return (str);
      str = str_add(str, revstr_nofree(str), base);
      i += 1;
      tab[0] = i;
    }
  return (str);
}

char *ini_all_palin(int *tab, int *check, int min, int max)
{
  char *str;

  str = malloc(sizeof(char) * 2);
  str[0] = '1';
  str[1] = '\0';
  tab[0] = min;
  tab[1] = max;
  *check = 0;
  return (str);
}

void all_palin(char *nb, int base, int min, int max)
{
  char *str;
  int tab[2];
  char *tmp;
  int check;

  if (is_palin(nb) != 0)
    error();
  str = ini_all_palin(tab, &check, min, max);
   if (nb[0] == '1' && my_len(nb) == 1)
    printf("%s, lead to %s in %d iteration(s) in base %d\n", nb, nb,
	   tab[0], base);
  while (check_nb(nb, str) != HIGH)
    {
      tmp = have_palin(revstr(revstr_nofree(str)), nb, base, tab);
      if (check_nb(nb, tmp) == OK && (check = 1) == 1)
	printf("%lld, lead to %lld in %d iteration(s) in base %d\n",
	       my_base(str, base), my_base(nb, base), tab[0], base);
      str = add_one(revstr(str), base);
      tab[0] = min;
      free(tmp);
    }
  if (check == 0)
    printf("no solution\n");
  free(str);
  free(nb);
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
	printf("no solus\n");
      else if (my_len(str) <= 32)
	{
	  printf("%d lead to %lld in %d iteration(s) in base %d\n",
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
