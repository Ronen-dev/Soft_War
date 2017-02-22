/*
** my_str_to_wordtab.c for  in /home/gentie_r/SVN-depots/piscine_c_Jour07/gentie_r/my_str_to_wordtab
** 
** Made by GENTIER Remi
** Login   <Gentie_r@etna-alternance.net>
** 
** Started on  Mon Mar 30 12:11:02 2015 GENTIER Remi
** Last update Mon Mar 30 15:48:33 2015 GENTIER Remi
*/

#include <stdlib.h>

int	count_word(char *str)
{
  int	i = 0;
  int	nb = 0;

  while (str[i])
    {
      while (str[i] && !((str[i] <= 'Z' && str[i] >= 'A') ||
			 (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9')))
	i++;
      while (str[i] && ((str[i] <= 'Z' && str[i] >= 'A') ||
			(str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9')))
	i++;
      nb++;
    }
  return (nb);
}

char	*cp_word(char *str)
{
  int	i = 0;
  char	*tmp;

  while (str[i] && ((str[i] <= 'Z' && str[i] >= 'A') ||
		    (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9')))
    i++;
  tmp = malloc(sizeof(*str) * (i + 1));
  tmp[i] = 0;
  i--;
  while (i >= 0)
    {
      tmp[i] = str[i];
      i--;
    }
  return (tmp);
}
char	**my_str_to_wordtab(char *str)
{
  char	**tmp = NULL;
  int	i = 0;
  int	nb = 0;

  tmp = malloc(sizeof(*tmp) * (count_word(str) + 1));
  tmp[count_word(str)] = NULL;
  
  while (str[i])
    {
      while (str[i] && !((str[i] <= 'Z' && str[i] >= 'A') ||
			 (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9')))
	i++;
      if (str[i])
	tmp[nb] = cp_word(&str[i]);
      while (str[i] && ((str[i] <= 'Z' && str[i] >= 'A') ||
			(str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9')))
	i++;
      nb++;
    }
  tmp[nb] = NULL;
  return (tmp);
}
