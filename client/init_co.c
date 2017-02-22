/*
** init_co.c for  in /home/instaa/client/coskun_a
** 
** Made by COSKUN Antoine
** Login   <coskun_a@etna-alternance.net>
** 
** Started on  Wed Jun 17 11:10:26 2015 COSKUN Antoine
** Last update Wed Jun 17 12:30:23 2015 COSKUN Antoine
*/

#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "main.h"

int			init_socket(t_sock *sock, char *host, int port)
{
  if ((sock->s = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    return (-1);
  sock->port = port;
  sock->sin.sin_family = AF_INET;
  sock->sin.sin_port = htons(sock->port);
  sock->sin.sin_addr.s_addr = inet_addr(host);
  return (0);
}

int		  	init_connexion(t_sock *sock, char *host, int port)
{
  if ((init_socket(sock, host, port)) == -1)
    return (-1);
  if (connect(sock->s, (struct sockaddr *)&(sock->sin),
              sizeof(struct sockaddr_in)) < 0)
    {
      my_putstr("Unable to connect!\n");
      return (-1);
    }
  my_putstr("Connexion established.\n");
  return (0);
}
