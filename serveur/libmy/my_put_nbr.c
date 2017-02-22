/*
** my_aff_chiffre.c for my_aff_chiffre in /home/gentie_r/SVN-depots/piscine_c_Jour01/gentie_r
** 
** Made by GENTIER Remi
** Login   <Gentie_r@etna-alternance.net>
** 
** Started on  Mon Mar 23 12:46:34 2015 GENTIER Remi
** Last update Thu Feb 11 17:11:00 2016 GENTIER Remi
*/

#include <unistd.h>

void	my_put_nbr(int t)
{
  char i = 0;

  if (t == -2147483648)
    {
      write(1, "-2147483648", 11);
      return;
    }
  if (t < 0)
    {  
      write(1, "-", 1);
      t = -t;
    }
  if (t > 9)
    my_put_nbr(t / 10);
  i = t % 10 + 48;
  write(1, &i, 1);
}
