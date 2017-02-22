/*
** client_function2.c for  in /home/gentier/softwar/mazouz_r/serveur
** 
** Made by GENTIER Remi
** Login   <gentie_r@etna-alternance.net>
** 
** Started on  Thu Feb 11 22:55:28 2016 GENTIER Remi
** Last update Thu Feb 11 23:41:10 2016 GENTIER Remi
*/

#include "softwar.h"

int	check_player_alive(t_info_game *game)
{
  int	i;
  int	c;

  for (i = 0, c = 0; i < 4; ++i)
    {
      if ((game->client)[i].alive == 1)
	c++;
    }
  if (c == 1)
  for (i = 0; i < 4; ++i)
    {
      if ((game->client)[i].alive == 1)
	{
	  write((game->client)[i].fd_client, "win", 3);
	  close_client((game->client)[i].fd_client, game);
	}
    }
  return (c);
}

int	init_game(t_info_game *game)
{
  int i;
  my_putstr("init_game begin\n");
  srand(time(NULL));
  if ((game->map = malloc(game->size *(sizeof(int*)))) == NULL)
    return (-1);
  for (i = 0; i < game->size; ++i)
    {
      if (((game->map)[i] = malloc(game->size *(sizeof(int)))) == NULL)
	return (-1);
    }
  (game->client)[0].positionx = 0;
  (game->client)[0].positiony = 0;
  (game->client)[0].name = rand() %99;
  (game->client)[0].power = 50;
  (game->map)[0][0] = 1;
  (game->client)[1].positionx = game->size - 1;
  (game->client)[1].positiony = 0;
  (game->map)[0][game->size - 1] = 2;
  (game->client)[1].name = rand() %99;
  (game->client)[1].power = 50;
  (game->client)[2].positionx = 0;
  (game->client)[2].positiony = game->size - 1;
  (game->map)[game->size - 1][0] = 3;
  (game->client)[2].name = rand() %99;
  (game->client)[2].power = 50;
  (game->client)[3].positionx = game->size - 1;
  (game->client)[3].positiony = game->size - 1;
  (game->map)[game->size - 1][game->size - 1] = 4;
  (game->client)[3].name = rand() %99;
  (game->client)[3].power = 50;
  (game->client)[0].orientation = 0; /*sud*/
  (game->client)[2].orientation = 1; /*est*/
  (game->client)[1].orientation = 2; /*ouest*/
  (game->client)[3].orientation = 3; /*nord*/
  (game->client)[0].alive = 1;
  (game->client)[2].alive = 1;
  (game->client)[1].alive = 1;
  (game->client)[2].alive = 1;
  return (1);
}
void my_put_nbr_str(int t, char str[][20], int n)
{
  if (t == -2147483648)
    {
      write(1, "-2147483648", 11);
      return;
    }
  if (t < 0)
    {
      write(1, "-", 1);
      t = -t;
    }
  if (t > 9)
    my_put_nbr_str(t / 10, str, n + 1);
  (*str)[n] = t % 10 + 48;

}
void	send_go(t_info_game *game)
{
  int	i;
  int	o;
  char buff[50];
  char buff2[20];
  char buff3[20];
  for (i = 0; i < 4; ++i)
    {
      for (o = 0; o < 50; o++)
	buff[o] = 0;
      for (o = 0; o < 20; o++)
	{
	  buff2[o]= 0;
	  buff3[o]= 0;
	}
      my_put_nbr_str((game->client)[i].positionx, &buff2, 0);
      my_put_nbr_str((game->client)[i].positiony, &buff3, 0);
      my_strcat(buff, buff2);
      my_strcat(buff, ", ");
      my_strcat(buff, buff3);
      my_strcat(buff, ", ");
      if ((game->client)[i].orientation == 0)
	my_strcat(buff, "S");
      if ((game->client)[i].orientation == 1)
	my_strcat(buff, "E");
      if ((game->client)[i].orientation == 2)
	my_strcat(buff, "N");
      if ((game->client)[i].orientation == 3)
	my_strcat(buff, "O");
      write((game->client)[i].fd_client, buff, 50);
    }
}
