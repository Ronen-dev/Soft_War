/*
** softwar.h for  in /home/gentier/softwar
** 
** Made by GENTIER Remi
** Login   <gentie_r@etna-alternance.net>
** 
** Started on  Wed Feb 10 09:50:54 2016 GENTIER Remi
** Last update Thu Feb 11 23:00:59 2016 GENTIER Remi
*/

#ifndef __SOFTWAR_H__
 #define __SOFTWAR_H__

#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

typedef struct s_fd_client
{
  int alive;
  int power;
  int orientation;
  int name;
  int positionx;
  int positiony;
  int fd_client;
  int free_slot;
}t_fd_client;
typedef struct s_connect
{
  int port;
  char *ip;
  int	listener;
  struct sockaddr_in serveraddr;
}t_connect;

typedef struct s_info_game
{
  t_fd_client client[4];
  int fd_max;
  fd_set read_fds;
  fd_set write_fds;
  int	newfd;
  int	size;
  int cycle;
  char *log;
  int **map;
}t_info_game;
typedef struct s_option_client
{
  char *cmd;
  int (*action)(t_info_game *, int);
}t_option_client;

int	is_num(char*, int);
int	find_port(int, char**, t_connect *);
int	find_size(int, char **, t_info_game *);
int	find_log(int, char **, t_info_game *);
int	find_cycle(int, char **, t_info_game *);
int	check_arg(int ac, char **, t_connect*, t_info_game *);
void	init_client(t_info_game*);
void	softwar(int ac, char **av);
int	check_four_player(t_info_game*);
int	add_client(t_info_game *);
void	close_client(int, t_info_game*);
int	check_player_alive(t_info_game*);
int	init_game(t_info_game *);
void	my_put_nbr_str(int, char str[][20], int);
void	send_go(t_info_game*game);
int	go_down(t_info_game*game, int);
int	go_up(t_info_game*, int);
int	go_right(t_info_game*, int);
int	go_left(t_info_game*, int);
int	my_strlen(char* str);
int	my_strcmp(char *str, char *str1);
int	my_getnbr(char *str);
void	my_putstr(char *str);
int	init_connection(t_connect *info);
int	loop_wait_client(t_connect *info, t_info_game *game);
int	loop_game(t_connect *info, t_info_game *game);
void	my_put_nbr(int);
char	*my_strcat(char*, char*);
int	forward(t_info_game *, int);
int	backward(t_info_game *, int);
int	leftfwd(t_info_game *, int);
int	rightfwd(t_info_game *, int);
int	right(t_info_game *, int);
int	left(t_info_game *, int);
int	orientation(t_info_game *, int);
int	gather(t_info_game *, int);
int	selfid(t_info_game *, int);
int	selfstatus(t_info_game *, int);
int	next(t_info_game *, int);
int	jump(t_info_game *, int);
#endif /*__SOFTWAR_H__*/
