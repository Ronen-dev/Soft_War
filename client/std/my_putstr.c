/*
** my_putstr.c for  in /home/coskun_a/libmyaskip/libmy_01
** 
** Made by COSKUN Antoine
** Login   <coskun_a@etna-alternance.net>
** 
** Started on  Sat Mar 28 12:12:07 2015 COSKUN Antoine
** Last update Wed Jun 17 11:58:06 2015 COSKUN Antoine
*/

#include "../main.h"

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '#')
	my_putchar('\n');
      else
	my_putchar(str[i]);
      ++i;
    }
}
