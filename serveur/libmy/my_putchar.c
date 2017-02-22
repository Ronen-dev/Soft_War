/*
** my_putchar.c for my_putchar in /home/gentie_r/SVN-depots/piscine_c_Jour01/gentie_r/my_putchar
** 
** Made by GENTIER Remi
** Login   <Gentie_r@etna-alternance.net>
** 
** Started on  Mon Mar 23 09:42:59 2015 GENTIER Remi
** Last update Mon Mar 23 12:21:50 2015 GENTIER Remi
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
