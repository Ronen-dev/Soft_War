/*
** my_put_nbr.c for  in /home/coskun_a/jour05/coskun_a/my_put_nbr
** 
** Made by COSKUN Antoine
** Login   <coskun_a@etna-alternance.net>
** 
** Started on  Fri Mar 27 14:00:41 2015 COSKUN Antoine
** Last update Wed Jun 17 11:57:38 2015 COSKUN Antoine
*/

#include "../main.h"

void	my_put_nbr(int nb)
{
  if (nb == -2147483648)
    my_putstr("-2147483648");
  else
    {
      if (nb < 0)
	{
	  my_putchar('-');
	  nb = nb * -1;
	}
      if (nb > 9)
	my_put_nbr(nb / 10);
      my_putchar((nb % 10) + 48);
    }
}
