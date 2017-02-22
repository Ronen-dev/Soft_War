/*
** my_getnbr.c for m in /home/gentie_r/SVN-depots/piscine_c_Jour05/gentie_r/my_getnbr
** 
** Made by GENTIER Remi
** Login   <Gentie_r@etna-alternance.net>
** 
** Started on  Fri Mar 27 13:13:07 2015 GENTIER Remi
** Last update Fri Mar 27 18:53:24 2015 GENTIER Remi
*/

int	my_getnbr(char *str)
{
  int	i = 0;
  int	res = 0;
  int	p = 0;
  int	m = -10;
  for (; (str[i] && (str[i] == '-' || str[i] == '+')); i++)
    if (str[i] == '-')
      p++;
  for (; str[i] && str[i] >= '0' && str[i] <= '9'; i++);
  i--;
  if (i == -1 || str[i] < '0' || str[i] > '9')
    return (0);
  res = (p % 2) == 0 ?  str[i] - '0' :  -(str[i] - '0');
  m = p % 2 == 0 ? -m : m;
  i--;
  for (; i >= 0 && str[i] >= '0' && str[i] <= '9'; i--)
    {
      res += (str[i] - '0') * m;
      m *= 10;
    }
  return (res);
}
