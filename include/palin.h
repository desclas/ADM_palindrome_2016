/*
** palin.h for  in /home/mathias/Bureau/projet_epitech/synthèse/ADM_palindrome_2016
** 
** Made by Mathias
** Login   <mathias.descoin@epitech.eu@epitech.net>
** 
** Started on  Thu Jun 15 16:53:56 2017 Mathias
** Last update Fri Jun 16 09:16:21 2017 Mathias
*/

#ifndef PALIN_H_
# define PALIN_H_

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>

# define N 0
# define P 2
# define B 4
# define MIN 6
# define MAX 8
# define FAIL -1
# define HIGH 1
# define OK 2
# define LOW -1

int my_len(char *str);
void inistr(char *str, int max);
int is_int(char *str);
char *append_char(char *str, char c);
char *revstr_nofree(char *str);
char *revstr(char *str);
char *my_int_to_str_base(int nb, int base);
char *str_add(char *nb, char *bn, int base);
int is_palin(char *str);
char *find_palin(char *nb, int base, int *min, int max);
void error(void);
void option(int av, char **ac);
long long int my_base(char *str, int base);
void initab(int *tab, int max);
void all_palin(char *nb, int base, int min, int max);
void error_all_palin(char *str, char *nb);

#endif /* !PALIN_H_ */
