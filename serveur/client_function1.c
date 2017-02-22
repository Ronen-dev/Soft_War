/*
** client_function1.c for  in /home/gentier/softwar/mazouz_r/serveur
** 
** Made by GENTIER Remi
** Login   <gentie_r@etna-alternance.net>
** 
** Started on  Thu Feb 11 22:44:55 2016 GENTIER Remi
** Last update Thu Feb 11 22:55:09 2016 GENTIER Remi
*/

#include "softwar.h"

void init_client(t_info_game *game)
{
  int	i;

  for (i = 0; i < 4; i++)
    {
      (game->client)[i].fd_client = 0;
      (game->client)[i].free_slot = 0;
    }
  return;
}

int	check_four_player(t_info_game *game)
{
  int  i;

  for (i = 0; i < 4; i++)
    {
      if ((game->client)[i].free_slot == 0)
	return (0);
    }
  return (1);
}

int	add_client(t_info_game *game)
{
  int	i;
  char buff[50];

  for (i = 0; i < 4; i++)
    {
      if (FD_ISSET((game->client)[i].fd_client, &(game->read_fds)))
	{
	  if (read(i,buff,50) <= 0)
	    {
	      close((game->client)[i].fd_client);
	      (game->client)[i].free_slot = 0;
	    }
	}
      if ((game->client)[i].free_slot == 0)
	{
	  (game->client)[i].free_slot = 1;
	  (game->client)[i].fd_client = game->newfd;
	  if (game->newfd > game->fd_max)
	    game->fd_max = game->newfd;
	  return (1);
	}
    }
  return (-1);
}
void	close_client(int i, t_info_game *game)
{
  int	p;

  for (p = 0; p < 4; ++p)
    {
      if ((game->client)[p].fd_client == i)
	{
	  (game->client)[p].fd_client = 0;
	  (game->client)[p].free_slot = 0;
	  (game->client)[p].alive = 0;
	  
	  my_putstr("Client close the connection\n");
	}
    }
}
