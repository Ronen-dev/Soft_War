/*
** function_mouvement.c for  in /home/gentier/softwar/mazouz_r/serveur
** 
** Made by GENTIER Remi
** Login   <gentie_r@etna-alternance.net>
** 
** Started on  Thu Feb 11 22:47:38 2016 GENTIER Remi
** Last update Thu Feb 11 23:19:40 2016 GENTIER Remi
*/

#include "softwar.h"

int go_down(t_info_game *game, int fd)
{
  int i;

  for (i = 0; i < 4; ++i)
    {
      if ((game->client)[i].fd_client == fd)
	{
	  (game->map)[(game->client)[i].positiony][(game->client)[i].positionx] = 0;
	  (game->client)[i].positiony += 1;
	  if ((game->client)[i].positiony >= game->size ||(game->client)[i].positionx >= game->size ||
	      (game->client)[i].positiony < 0 || (game->client)[i].positionx < 0)
	    {
	      write((game->client)[i].fd_client, "die", 3);
	      close_client((game->client)[i].fd_client, game);
	      return (1);
	    }
	  (game->map)[(game->client)[i].positiony][(game->client)[i].positionx] = i + 1;
	}
   }
  return (1);
}

int go_up(t_info_game *game, int fd)
{
  int i;

  for (i = 0; i < 4; ++i)
    {
      if ((game->client)[i].fd_client == fd)
	{
	  (game->map)[(game->client)[i].positiony][(game->client)[i].positionx] = 0;
	  (game->client)[i].positiony -= 1;
	  if ((game->client)[i].positiony >= game->size ||(game->client)[i].positionx >= game->size ||
	      (game->client)[i].positiony < 0 || (game->client)[i].positionx < 0)
	    {
	      write((game->client)[i].fd_client, "die", 3);
	      close_client((game->client)[i].fd_client, game);
	      return (1);
	    }
	  (game->map)[(game->client)[i].positiony][(game->client)[i].positionx] = i + 1;
	}
   }
  return (1);
}

int go_right(t_info_game *game, int fd)
{
  int i;

  for (i = 0; i < 4; ++i)
    {
      if ((game->client)[i].fd_client == fd)
	{
	  (game->map)[(game->client)[i].positiony][(game->client)[i].positionx] = 0;
	  (game->client)[i].positionx += 1;
	  if ((game->client)[i].positiony >= game->size ||(game->client)[i].positionx >= game->size || (game->client)[i].positiony < 0 || (game->client)[i].positionx < 0)
	    {
	      write((game->client)[i].fd_client, "die", 3);
	      close_client((game->client)[i].fd_client, game);
	      return (1);
	    }
	  (game->map)[(game->client)[i].positiony][(game->client)[i].positionx] = i + 1;
	}
   }
  return (1);
}
int go_left(t_info_game *game, int fd)
{
  int i;

  for (i = 0; i < 4; ++i)
    {
      if ((game->client)[i].fd_client == fd)
	{
	  (game->map)[(game->client)[i].positiony][(game->client)[i].positionx] = 0;
	  (game->client)[i].positiony -= 1;
	  if ((game->client)[i].positiony >= game->size ||(game->client)[i].positionx >= game->size || (game->client)[i].positiony < 0 || (game->client)[i].positionx < 0)
	    {
	      write((game->client)[i].fd_client, "die", 3);
	      close_client((game->client)[i].fd_client, game);
	      return (1);
	    }
	  (game->map)[(game->client)[i].positiony][(game->client)[i].positionx] = i + 1;
	}
   }
  return (1);
}
