/*
** init_connection.c for  in /home/gentier/softwar
** 
** Made by GENTIER Remi
** Login   <gentie_r@etna-alternance.net>
** 
** Started on  Wed Feb 10 09:56:08 2016 GENTIER Remi
** Last update Thu Feb 11 23:37:23 2016 GENTIER Remi
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "softwar.h"

int	init_connection(t_connect *data)
{
  struct sockaddr_in serveraddr;
  if ((data->listener = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
      my_putstr("Error socket server\n");
      return (-1);
    }
  serveraddr.sin_family = AF_INET;
  serveraddr.sin_addr.s_addr = INADDR_ANY;
  serveraddr.sin_port = htons(data->port);
  if (bind(data->listener, (struct sockaddr *)&(serveraddr),
	  sizeof(serveraddr)) == -1)
    {
      my_putstr("Server-bind error\n");
      return (-1);
    }
  if (listen(data->listener, 1) == -1)
    {
      my_putstr("Server listen error\n");
      return (-1);
    }
  return (1);
}
