/*
** my_strncat.c for  in /home/gentie_r/SVN-depots/piscine_c_Jour04/gentie_r/my_strncat
** 
** Made by GENTIER Remi
** Login   <Gentie_r@etna-alternance.net>
** 
** Started on  Thu Mar 26 09:54:36 2015 GENTIER Remi
** Last update Thu Mar 26 11:59:58 2015 GENTIER Remi
*/

char	*my_strncat(char *d, char *s, int n)
{
  int	i = 0;
  int	m = 0;

  while (d[i])
    ++i;
  while (s[m] && m < n)
    {
      d[i + m] = s[m];
      m++;
    }
  d[i + m] = 0;
  return (d);
}
