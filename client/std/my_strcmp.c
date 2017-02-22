/*
** my_strcmp.c for  in /home/coskun_a/libmyaskip/libmy_01
** 
** Made by COSKUN Antoine
** Login   <coskun_a@etna-alternance.net>
** 
** Started on  Sat Mar 28 12:12:07 2015 COSKUN Antoine
** Last update Wed Jun 17 11:58:06 2015 COSKUN Antoine
*/

#include "../main.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i])
    {
      if (s1[i] < s2[i])
	return (-1);
      else if (s1[i] > s2[i])
	return (1);
      ++i;
    }
  if (s1[i] < s2[i])
    return (-1);
  else if (s1[i] > s2[i])
    return (1);
  return (0);
}
