/*
** function_mouvement4.c for  in /home/gentier/softwar/mazouz_r/serveur
** 
** Made by GENTIER Remi
** Login   <gentie_r@etna-alternance.net>
** 
** Started on  Thu Feb 11 22:49:37 2016 GENTIER Remi
** Last update Thu Feb 11 23:34:40 2016 GENTIER Remi
*/

#include "softwar.h"

int	gather(t_info_game *game, int fd)
{
  write(fd, "ok", 2);
  if (fd > 0 && game != NULL)
    return (1);
  return (1);
}

int left(t_info_game *game, int fd)
{
  int i;
  for (i = 0; i < 4; ++i)
    {
      if ((game->client)[i].fd_client == fd)
	{
	  if ((game->client)[i].orientation == 1)
	    {
	      (game->client)[i].orientation +=1;
	      return (write(fd, "ok", 2));
	    }
	  if ((game->client)[i].orientation == 0)
	    {
	      (game->client)[i].orientation +=1;
	    return (write(fd, "ok", 2));
	    }
	  if ((game->client)[i].orientation == 2)
	    {
	      (game->client)[i].orientation +=1;
	    return (write(fd, "ok", 2));
	    }
	  if ((game->client)[i].orientation == 3)
	    {
	      (game->client)[i].orientation = 0;
	    return (write(fd, "ok", 2));
	    }
	}
    }
  return (1);
}
int right(t_info_game *game, int fd)
{
  int i;
  for (i = 0; i < 4; ++i)
    {
      if ((game->client)[i].fd_client == fd)
	{
	  if ((game->client)[i].orientation == 1)
	    {
	      (game->client)[i].orientation -= 1;
	      return (write(fd, "ok", 2));
	    }
	  if ((game->client)[i].orientation == 0)
	    {
	      (game->client)[i].orientation = 3;
	      return (write(fd, "ok", 2));
	    }
	  if ((game->client)[i].orientation == 2)
	    {
	      (game->client)[i].orientation -= 1;
	      return (write(fd, "ok", 2));
	    }
	  if ((game->client)[i].orientation == 3)
	    {
	      (game->client)[i].orientation -= 1;
	      return (write(fd, "ok", 2));
	    }
	}
    }
  return (1);
}
