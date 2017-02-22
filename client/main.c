/*
** main.c for  in /home/instaa/client/coskun_a
** 
** Made by COSKUN Antoine
** Login   <coskun_a@etna-alternance.net>
** 
** Started on  Wed Jun 17 11:07:33 2015 COSKUN Antoine
** Last update Wed Jun 17 12:21:18 2015 COSKUN Antoine
*/

#include <stdlib.h>
#include <unistd.h>
#include "main.h"

void		clean_buffer(char *buf)
{
  int		i;

  for (i = 0; i < 4096; i++)
    buf[i] = '\0';
}

int		check_bye(char *buf)
{
  if (my_strcmp(buf, "/bye\n") == 0)
    {
      free(buf);
      return (0);
    }
  return (1);
}

int		loop(t_sock *sock)
{
  char		*buf;
  char		buf2[4096];
  int		i;

  while ((buf = readLine()) && check_bye(buf))
    {
      if (buf[0] != '\n')
	{
	  if (write(sock->s, buf, my_strlen(buf)) == -1)
	    return (-1);
	  for (i = 1; buf2[i - 1] != '\n';)
	    {
	      if ((i = read(sock->s, buf2, 4095)) == -1)
		return (-1);
            buf2[i] = '\0';
	      my_putstr(buf2);
	    }
	  clean_buffer(buf2);
	  free(buf);
	}
    }
  return (0);
}

int		verify_args(int ac, char **args)
{
  if ((ac != 5) ||
      (my_strcmp(args[1], "--ip") != 0)	  ||
      (my_strcmp(args[3], "--port") != 0))
    {
      my_putstr("Usage : /client --ip [ip] --port [port]\n");
      return (1);
    }
  return (0);
}

int		main(int ac, char **av)
{
  t_sock	sock;

  if (verify_args(ac, av) == 0)
    {
      if ((init_connexion(&sock, av[2], my_getnbr(av[4]))) == -1)
		return (-1);
      loop(&sock);
      close(sock.s);
    }
  return (0);
}
