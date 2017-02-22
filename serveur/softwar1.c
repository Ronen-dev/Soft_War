/*
** softwar1.c for  in /home/gentier/softwar/mazouz_r/serveur
** 
** Made by GENTIER Remi
** Login   <gentie_r@etna-alternance.net>
** 
** Started on  Thu Feb 11 23:04:35 2016 GENTIER Remi
** Last update Thu Feb 11 23:12:26 2016 GENTIER Remi
*/

#include "softwar.h"

int	is_num(char *str, int size)
{
  int	i;

  if (my_strlen(str) >= 2 && my_strlen(str) <= size)
    {
      for (i = 0; str[i]; i++)
	if (str[i] < '0' || str[i] > '9')
	  return (-1);
      return (1);
    }
  return (-1);
}

int	find_port(int ac, char **av, t_connect *server_data)
{
  int	i;

  for (i = 0; i < ac; i++)
    {
      if (my_strcmp("--port", av[i]) == 0 && i + 1 < ac &&
	  is_num(av[i + 1], 5) == 1)
	{
	  server_data->port = my_getnbr(av[i + 1]);
	  return (1);
	}
    }
  return (-1);
}

int	find_size(int ac, char **av, t_info_game *game)
{
  int	i;

  for (i = 0; i < ac; i++)
    {
      if (my_strcmp("--size", av[i]) == 0)
	{
	  if (i + 1 < ac && is_num(av[i + 1], 10) == 1)
	    {
	      game->size = my_getnbr(av[i + 1]);
	      return (1);
	    }
	  else
	    return (-1);
	}
    }
  return (1);
}

int	find_log(int ac, char **av, t_info_game *game)
{
  int i;

  for (i = 0; i < ac; i++)
    {
      if (my_strcmp("--log", av[i]) == 0)
	{
	  if (i + 1 < ac && av[i + 1][0] == '/')
	    {
	      game->log = av[i + 1];
	      return (1);
	    }
	  else
	    return (-1);
	}
    }
  return (1);
}
