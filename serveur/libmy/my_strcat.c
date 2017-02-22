/*
** my_strcat.c for  in /home/gentie_r/SVN-depots/piscine_c_Jour04/gentie_r/my_strcat
** 
** Made by GENTIER Remi
** Login   <Gentie_r@etna-alternance.net>
** 
** Started on  Thu Mar 26 09:50:16 2015 GENTIER Remi
** Last update Thu Mar 26 09:53:01 2015 GENTIER Remi
*/

char	*my_strcat(char *d, char *s)
{
  int	i = 0;
  int	m = 0;

  while (d[i])
    i++;
  while (s[m])
    {
      d[i + m] = s[m];
      m++;
    }
  d[i + m] = '\0';
  return (d);
}
