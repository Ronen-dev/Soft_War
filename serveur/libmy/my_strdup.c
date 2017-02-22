/*
** my_strdup.c for  in /home/gentie_r/SVN-depots/piscine_c_Jour07/gentie_r/my_strdup
** 
** Made by GENTIER Remi
** Login   <Gentie_r@etna-alternance.net>
** 
** Started on  Mon Mar 30 11:02:41 2015 GENTIER Remi
** Last update Mon Mar 30 12:16:52 2015 GENTIER Remi
*/

#include <stdlib.h>
char	*my_strcpy(char*, char*);
int	my_strlen(char *);

char	*my_strdup(char *str)
{
  char	*tmp = NULL;
  int	i = my_strlen(str);

  tmp = malloc(sizeof(*tmp) * (i + 1));
  tmp = my_strcpy(tmp, str);
  return (tmp);
}
