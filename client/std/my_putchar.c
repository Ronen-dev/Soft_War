/*
** my_putchar.c for  in /home/coskun_a/libmyaskip/libmy_01
** 
** Made by COSKUN Antoine
** Login   <coskun_a@etna-alternance.net>
** 
** Started on  Sat Mar 28 11:55:58 2015 COSKUN Antoine
** Last update Sat Mar 28 11:56:22 2015 COSKUN Antoine
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
