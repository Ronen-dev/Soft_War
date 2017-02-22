/*
** readline.c for  in /home/coskun_a/sujet_colle/public/roulette
** 
** Made by COSKUN Antoine
** Login   <coskun_a@etna-alternance.net>
** 
** Started on  Sat Mar 28 09:28:56 2015 COSKUN Antoine
** Last update Sat Mar 28 09:38:57 2015 COSKUN Antoine
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

char		*readLine()
{
  ssize_t	ret;
  char		*buff;

  write(1, "$> ", 3);
  if ((buff = malloc(sizeof(*buff) * (250 + 1))) == NULL)
    return (NULL);
  if ((ret = read(0, buff, 250)) >= 1)
    {
      buff[ret] = '\0';
      return (buff);
    }
  buff[0] = '\0';
  return (buff);
}
