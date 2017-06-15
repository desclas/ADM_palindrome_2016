/*
** test.c for  in /home/mathias/Bureau/projet_epitech/synthèse/ADM_palindrome_2016
** 
** Made by Mathias
** Login   <mathias.descoin@epitech.eu@epitech.net>
** 
** Started on  Thu Jun 15 11:48:33 2017 Mathias
** Last update Thu Jun 15 16:27:21 2017 Mathias
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#define N 0
#define P 2
#define B 4
#define MIN 6
#define MAX 8
#define FAIL -1

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

  str = malloc(sizeof(char));
  str[0] = '\0';
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

long long int my_convert_base(char *str, int base)
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
		 tab[N + 1], my_convert_base(str, tab[B + 1]), nb, tab[B + 1]);
	  free(str);
	}
    }
  else if (tab[P] == 1)
    printf("construction\n");
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
