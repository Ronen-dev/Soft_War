/*
** function_mouvement2.c for  in /home/gentier/softwar/mazouz_r/serveur
** 
** Made by GENTIER Remi
** Login   <gentie_r@etna-alternance.net>
** 
** Started on  Thu Feb 11 22:48:22 2016 GENTIER Remi
** Last update Thu Feb 11 23:31:38 2016 GENTIER Remi
*/

#include "softwar.h"

int leftfwd(t_info_game *game, int fd)
{
  int i;
  for (i = 0; i < 4; ++i)
    {
      if ((game->client)[i].fd_client == fd)
	{
	  if ((game->client)[i].orientation == 1)
	    {
	      (game->client)[i].orientation +=1;
	      return (go_up(game, fd) && write(fd, "ok", 2));
	    }
	  if ((game->client)[i].orientation == 0)
	    {
	      (game->client)[i].orientation +=1;
	    return (go_right(game, fd) && write(fd, "ok", 2));
	    }
	  if ((game->client)[i].orientation == 2)
	    {
	      (game->client)[i].orientation +=1;
	    return (go_left(game, fd) && write(fd, "ok", 2));
	    }
	  if ((game->client)[i].orientation == 3)
	    {
	      (game->client)[i].orientation = 0;
	    return (go_down(game, fd) && write(fd, "ok", 2));
	    }
	}
    }
  return (1);
}

int rightfwd(t_info_game *game, int fd)
{
  int i;
  for (i = 0; i < 4; ++i)
    {
      if ((game->client)[i].fd_client == fd)
	{
	  if ((game->client)[i].orientation == 1)
	    {
	      (game->client)[i].orientation -= 1;
	      return (go_down(game, fd) && write(fd, "ok", 2));
	    }
	  if ((game->client)[i].orientation == 0)
	    {
	      (game->client)[i].orientation = 3;
	      return (go_left(game, fd) && write(fd, "ok", 2));
	    }
	  if ((game->client)[i].orientation == 2)
	    {
	      (game->client)[i].orientation -= 1;
	      return (go_right(game, fd) && write(fd, "ok", 2));
	    }
	  if ((game->client)[i].orientation == 3)
	    {
	      (game->client)[i].orientation -= 1;
	      return (go_up(game, fd) && write(fd, "ok", 2));
	    }
	}
    }
  return (1);
}
int backward(t_info_game *game, int fd)
{
  int i;

  for (i = 0; i < 4; ++i)
    {
      if ((game->client)[i].fd_client == fd)
	{
	  if ((game->client)[i].orientation == 1)
	    return (go_right(game, fd) && write(fd, "ok", 2));
	  if ((game->client)[i].orientation == 0)
	    return (go_up(game, fd) && write(fd, "ok", 2));
	  if ((game->client)[i].orientation == 2)
	    return (go_left(game, fd) && write(fd, "ok", 2));
	  if ((game->client)[i].orientation == 3)
	    return (go_down(game, fd) && write(fd, "ok", 2));
	}
    }
  return (1);
}
int forward(t_info_game *game, int fd)
{
  int i;

  for (i = 0; i < 4; ++i)
    {
      if ((game->client)[i].fd_client == fd)
	{
	  if ((game->client)[i].orientation == 1)
	    return (go_left(game, fd) && write(fd, "ok", 2));
	  if ((game->client)[i].orientation == 0)
	    return (go_down(game, fd) && write(fd, "ok", 2));
	  if ((game->client)[i].orientation == 2)
	    return (go_right(game, fd) && write(fd, "ok", 2));
	  if ((game->client)[i].orientation == 3)
	    return (go_up(game, fd) && write(fd, "ok", 2));
	}
    }
  return (1);
}

int jump(t_info_game *game, int fd)
{
  int i;

  for (i = 0; i < 4; ++i)
    {
      if ((game->client)[i].fd_client == fd)
	{
	  if ((game->client)[i].orientation == 1)
	    return (go_left(game, fd) && go_left(game, fd) && write(fd, "ok", 2));
	  if ((game->client)[i].orientation == 0)
	    return (go_down(game, fd) && go_down(game, fd) && write(fd, "ok", 2));
	  if ((game->client)[i].orientation == 2)
	    return (go_right(game, fd) && go_right(game, fd) && write(fd, "ok", 2));
	  if ((game->client)[i].orientation == 3)
	    return (go_up(game, fd) && go_up(game, fd) && write(fd, "ok", 2));
	}
    }
  return (1);
}
