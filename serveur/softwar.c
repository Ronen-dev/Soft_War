/*
** softwar.c for  in /home/gentier/softwar
** 
** Made by GENTIER Remi
** Login   <gentie_r@etna-alternance.net>
** 
** Started on  Wed Feb 10 10:46:49 2016 GENTIER Remi
** Last update Fri Feb 12 09:06:44 2016 GENTIER Remi
*/

#include <stdio.h>
#include <stdlib.h>
#include "softwar.h"

int	find_cycle(int ac, char **av, t_info_game *game)
{
  int	i;

  for (i = 0; i < ac; i++)
    {
      if (my_strcmp("--cycle", av[i]) == 0)
	{
	  if (i + 1 < ac && is_num(av[i + 1], 10) == 1)
	    {
	      game->cycle = my_getnbr(av[i + 1]);
	      return (1);
	    }
	  else
	    return (-1);
	}
    }
  return (1);
}
int	check_arg(int ac, char **av, t_connect *server_data, t_info_game *game)
{
  if (find_port(ac, av, server_data) == -1)
    {
      my_putstr("Vous devez choisir un port\n");
      return (-1);
    }
  if (find_size(ac, av, game) == -1 || find_log(ac, av, game) == -1 ||
      find_cycle(ac, av, game) == -1)
    return (-1);
  return (1);
}

void	init_data(t_connect *server_data, t_info_game *game)
{
  server_data->port = 0;
  game->cycle = 500000;
  game->log = NULL;
  game->size = 10;
}
void	softwar(int ac, char **av)
{
  t_connect server_data;
  t_info_game	game;

  if (check_arg(ac, av, &server_data, &game) == -1)
    {
      my_putstr("usage: ./server [--size size(10-9 999 999 999)] [-v] [--log] [--cycle time(10-9 999 999 999)] [--port port(10-99999 )]\n");
      return;
    }
  if (init_connection(&server_data) == -1)
    {
      my_putstr("Server-init error\n");
      return;
    }
  if (loop_wait_client(&server_data, &game) == -1)
    {
      my_putstr("sever boucle wait client error\n");
      return;
    }
  if (loop_game(&server_data, &game) == -1)
    {
      my_putstr("server error boucle game\n");
      return;
    }
  return;
}
