/*
** my_getnbr.c for  in /home/coskun_a/jour05/coskun_a/my_getnbr
** 
** Made by COSKUN Antoine
** Login   <coskun_a@etna-alternance.net>
** 
** Started on  Fri Mar 27 14:02:32 2015 COSKUN Antoine
** Last update Mon Mar 30 11:27:22 2015 COSKUN Antoine
*/

int	my_neg(char *str)
{
  int	i;
  int	s;

  i = 0;
  s = 1;
  while (!(str[i] < '9' && str[i] > '0'))
    {
      if (str[i] == '-')
	s = s * -1;
      ++i;
    }
  return (s);
}

int	my_getnbr(char *str)
{
  int	i;
  int	nb;

  i = 0;
  nb = 0;
  while (str[i] == '-' || str[i] == '+')
    ++i;
  while (str[i] >= '0' && str[i] <= '9')
    {
      nb = nb + (str[i] - 48);
      if (str[i + 1] >= '0' && str[i + 1] <= '9')
	nb = nb * 10;
      ++i;
    }
  return (nb * my_neg(str));
}
