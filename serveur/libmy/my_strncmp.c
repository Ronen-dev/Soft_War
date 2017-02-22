/*
** my_strncmp.c for  in /home/gentie_r/SVN-depots/piscine_c_Jour04/gentie_r/my_strncmp
** 
** Made by GENTIER Remi
** Login   <Gentie_r@etna-alternance.net>
** 
** Started on  Thu Mar 26 09:44:04 2015 GENTIER Remi
** Last update Thu Mar 26 11:42:11 2015 GENTIER Remi
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i = 0;

  while (s1[i] && s2[i] && i < n)
    {
      if (s1[i] < s2[i])
	return (-1);
      if (s1[i] > s2[i])
	return (1);
      i++;
    }
  if (i == n)
    return (0);
  if (s1[i] < s2[i])
    return (-1);
  if (s1[i] > s2[i])
    return (1);
  return (0);
}
