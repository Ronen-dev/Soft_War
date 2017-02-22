/*
** function_mouvement3.c for  in /home/gentier/softwar/mazouz_r/serveur
** 
** Made by GENTIER Remi
** Login   <gentie_r@etna-alternance.net>
** 
** Started on  Thu Feb 11 22:49:11 2016 GENTIER Remi
** Last update Thu Feb 11 23:33:42 2016 GENTIER Remi
*/

#include "softwar.h"

int	orientation(t_info_game *game, int fd)
{
  int i;
  for (i = 0; i < 4; ++i)
    {
      if ((game->client)[i].fd_client == fd)
	{
	  if ((game->client)[i].orientation == 1)
	    write(fd, "E", 1);
	  if ((game->client)[i].orientation == 0)
	    write(fd, "S", 1);
	  if ((game->client)[i].orientation == 2)
	    write(fd, "N", 1);
	  if ((game->client)[i].orientation == 3)
	    write(fd, "O", 1);
	}
    }
  return (1);
}

int	selfid(t_info_game *game, int fd)
{
  int i;
  int o;
  char buff[50];
  char buff2[20];
  for (i = 0; i < 4; ++i)
    {
      if ((game->client)[i].fd_client == fd)
	{
	  for (o = 0; o < 50; o++)
	    buff[o] = 0;
	  for (o = 0; o < 20; o++)
	    buff2[o]= 0;
	  my_put_nbr_str((game->client)[i].name, &buff2, 0);
	  my_strcat(buff, "#0x");
	  my_strcat(buff, buff2);
	  write(fd, buff, 50);
	}
    }
  return (1);
}

int	selfstatus(t_info_game *game, int fd)
{
  int i;
  int o;
  char buff2[20];
  for (i = 0; i < 4; ++i)
    {
      if ((game->client)[i].fd_client == fd)
	{
	  for (o = 0; o < 20; o++)
	    buff2[o] = 0;
	  my_put_nbr_str((game->client)[i].power, &buff2, 0);
	  write(fd, buff2, 20);
	}
    }
  return (1);
}
int	next(t_info_game *game, int fd)
{
  write(fd, "ok", 2);
  if (fd > 0 && game != NULL)
    return (1);
  return (1);
}
