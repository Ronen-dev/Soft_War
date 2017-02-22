/*
** main.h for  in /home/instaa/client/coskun_a
** 
** Made by COSKUN Antoine
** Login   <coskun_a@etna-alternance.net>
** 
** Started on  Wed Jun 17 11:20:01 2015 COSKUN Antoine
** Last update Wed Jun 17 12:19:09 2015 COSKUN Antoine
*/

#ifndef _client_H_
# define _client_H_

#include <netinet/in.h>

typedef struct		s_sock
{
  int			s;
  struct sockaddr_in	sin;
  int			port;
}			t_sock;

// STD
void			my_memcpy(void *, void *, int);
void			my_putchar(char);
int			my_strlen(char *);
void			my_putstr(char *);
int			my_strcmp(char *, char *);
int			my_getnbr(char *);
void			my_put_nbr(int);
char			*readLine();

// INIT_CO
int			init_socket(t_sock *, char *, int);
int			init_connexion(t_sock *, char *, int);

// MAIN
int			loop(t_sock *);
int			verify_args(int, char **);
void			clean_buffer(char *);
int			check_bye(char *);

#endif /* !_client_H_ */
