/*
** my_strcmp.c for  in /home/gentie_r/SVN-depots/piscine_c_Jour04/gentie_r/my_strcmp
** 
** Made by GENTIER Remi
** Login   <Gentie_r@etna-alternance.net>
** 
** Started on  Thu Mar 26 09:38:26 2015 GENTIER Remi
** Last update Thu Mar 26 10:08:02 2015 GENTIER Remi
*/

int	my_strcmp(char *src1, char *src2)
{
  int	i = 0;

  while (src1[i] && src2[i])
    {
      if (src1[i] < src2[i])
	return (-1);
      if (src1[i] > src2[i])
	return (1);
      i++;
    }
  if (src1[i] < src2[i])
    return (-1);
  else if (src1[i] > src2[i])
    return (1);
  else
    return (0);
}
