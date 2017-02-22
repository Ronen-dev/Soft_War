/*
** my_strstr.c for  in /home/gentie_r/SVN-depots/piscine_c_Jour04/gentie_r/my_strstr
** 
** Made by GENTIER Remi
** Login   <Gentie_r@etna-alternance.net>
** 
** Started on  Thu Mar 26 10:27:09 2015 GENTIER Remi
** Last update Mon Mar 30 09:52:30 2015 GENTIER Remi
*/

int	my_strncmp1(char *s1, char *s2, int n)
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

char	*my_strstr(char *s1, char*s2)
{
  int	i = 0;
  int	size = 0;
  while (s2[size])
    size++;
  while (s1[i])
    {
      if (my_strncmp1(&s1[i], s2, size) == 0)
	return (&s1[i]);
      ++i;
    }
  return ("null");
}
