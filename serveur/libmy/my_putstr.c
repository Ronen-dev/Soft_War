/*
** my_putstr.c for l in /home/gentie_r/SVN-depots/piscine_c_Jour03/gentie_r/my_putstr
** 
** Made by GENTIER Remi
** Login   <Gentie_r@etna-alternance.net>
** 
** Started on  Wed Mar 25 09:04:33 2015 GENTIER Remi
** Last update Mon Apr  6 17:07:57 2015 GENTIER Remi
*/

#include <unistd.h>

void	my_putstr(char *str)
{
  while (*str)
    write(1, str++, 1);
}
