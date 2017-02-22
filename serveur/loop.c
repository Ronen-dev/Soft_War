/*
** loop.c for  in /home/gentier/softwar
** 
** Made by GENTIER Remi
** Login   <gentie_r@etna-alternance.net>
** 
** Started on  Wed Feb 10 14:31:31 2016 GENTIER Remi
** Last update Thu Feb 11 23:35:52 2016 GENTIER Remi
*/

#include "softwar.h"

t_option_client cmd[12] = {{"forward\n", forward},
			   {"backward\n", backward},
			   {"rightfwd\n", rightfwd},
			   {"leftfwd\n", leftfwd},
			   {"orientation\n", orientation},
			   {"gather\n", gather},
			   {"selfid\n", selfid},
			   {"next\n", next},
			   {"selfstatus\n", selfstatus},
			   {"right\n", right},
			   {"left\n", left},
			   {"jump\n", jump}};

int loop_wait_client(t_connect *server_data, t_info_game *game)
{
  int	i;
  int addrlen;
  char buff[50];
  struct sockaddr_in serveraddr;
  serveraddr.sin_family = AF_INET;
  serveraddr.sin_addr.s_addr = INADDR_ANY;
  serveraddr.sin_port = htons(server_data->port);

  init_client(game);
  game->fd_max = server_data->listener;
  while (check_four_player(game) == 0)
    {
      FD_ZERO(&(game->read_fds));
      FD_SET(server_data->listener, &(game->read_fds));
      for (i = 0; i < 4; ++i)
	{
	  if ((game->client)[i].free_slot == 1)
	    FD_SET((game->client)[i].fd_client, &(game->read_fds));
	  if ((game->client)[i].fd_client > game->fd_max)
	    game->fd_max = (game->client)[i].fd_client;
	}
      if (select(game->fd_max + 1, &(game->read_fds), NULL, NULL, NULL) == -1)
	{
	  my_putstr("Server-select error\n");
	  return (-1);
	}
      for (i = 0; i <= game->fd_max; i++)
	{
	  if (FD_ISSET(i, &(game->read_fds)))
	    {
	      if (i == server_data->listener)
		{
		  addrlen = sizeof(struct sockaddr_in);
		  if ((game->newfd = accept(server_data->listener, (struct sockaddr *)&(serveraddr), (socklen_t *)&addrlen)) == -1)
		    my_putstr("server accept error\n");
		  else
		    {
		      if (add_client(game) == -1)
			{
			  my_putstr("close client\n");
			  close(game->newfd);
			}
		      else
			{
			  write(game->newfd, "ok", 2);
			  my_putstr("server accept new client\n");
			}
		    }
		}
	      else
		{
		  int re;
		  if ((re = read(i, buff, 50)) <= 0)
		    close_client(i, game);
		  else
		    {
		      buff[(re < 50 ? re : 49)] = 0;
		      my_putstr(buff);
		    }
		}
	    }
	}
    }
  return (1);
}

int loop_game(t_connect *server_data, t_info_game *game)
{
  int	i;
  int addrlen;
  char buff[1024];
  struct sockaddr_in serveraddr;
  if (init_game(game) == -1)
    return (-1);
  send_go(game);
  serveraddr.sin_family = AF_INET;
  serveraddr.sin_addr.s_addr = INADDR_ANY;
  serveraddr.sin_port = htons(server_data->port);
  while (check_player_alive(game) > 1)
    {
      FD_ZERO(&(game->read_fds));
      FD_SET(server_data->listener, &(game->read_fds));
      for (i = 0; i < 4; ++i)
	{
	  if ((game->client)[i].free_slot == 1)
	    FD_SET((game->client)[i].fd_client, &(game->read_fds));
	  if ((game->client)[i].fd_client > game->fd_max)
	    game->fd_max = (game->client)[i].fd_client;
	}
      if (select(game->fd_max + 1, &(game->read_fds), NULL, NULL, NULL) == -1)
	{
	  my_putstr("Server-select error\n");
	  return (-1);
	}
      for (i = 0; i <= game->fd_max; i++)
	{
	  if (FD_ISSET(i, &(game->read_fds)))
	    {
	      if (i == server_data->listener)
		{
		  addrlen = sizeof(struct sockaddr_in);
		  if ((game->newfd = accept(server_data->listener, (struct sockaddr *)&(serveraddr), (socklen_t *)&addrlen)) == -1)
		    my_putstr("server accept error\n");
		  else
		    close(game->newfd);
		}
	      else
		{
		  int re;
		  if ((re = read(i, buff, 1024)) <= 0)
		    close_client(i, game);
		  else
		    {
		      buff[(re < 1024 ? re : 1024)] = 0;
		      my_putstr(buff);
		      for (re = 0; re < 11; re++)
			{
			  if (my_strcmp(cmd[re].cmd, buff) == 0)
			    {
			      my_putstr(buff);
			      cmd[re].action(game, i);
			      break;
			    }
			}
		      if (re == 11)
			write(i, "ko", 2);
		    }
		}
	    }
	}
    }
  return (1);
}
