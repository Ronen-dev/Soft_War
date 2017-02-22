/*
** my_strlen.c for l in /home/gentie_r/SVN-depots/piscine_c_Jour03/gentie_r/my_strlen
** 
** Made by GENTIER Remi
** Login   <Gentie_r@etna-alternance.net>
** 
** Started on  Wed Mar 25 09:14:03 2015 GENTIER Remi
** Last update Wed Mar 25 09:31:12 2015 GENTIER Remi
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}
