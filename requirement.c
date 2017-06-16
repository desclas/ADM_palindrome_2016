/*
** requirement.c for  in /home/mathias/Bureau/projet_epitech/synthèse/ADM_palindrome_2016
** 
** Made by Mathias
** Login   <mathias.descoin@epitech.eu@epitech.net>
** 
** Started on  Thu Jun 15 09:16:28 2017 Mathias
** Last update Fri Jun 16 14:07:32 2017 Mathias
*/

#include <stdlib.h>

int my_factrec_synthesis(int nb)
{
  return (nb * (nb < 0 ? 0 : (nb == 1 || nb == 0 ? 1 :
			      my_factrec_synthesis(nb - 1))));
}

int my_squareroot_synthesis(int nb)
{
  int i;

  i = 1;
  if (nb == 0)
    return (0);
  if (nb < 0)
    return (-1);
  while (i * i < nb)
    i += 1;
  if (i * i == nb)
    return (i);
  return (-1);
}
