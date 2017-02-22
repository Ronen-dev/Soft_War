/*
** my_strcpy.c for  in /home/gentie_r/SVN-depots/piscine_c_Jour04/gentie_r/my_strcpy
** 
** Made by GENTIER Remi
** Login   <Gentie_r@etna-alternance.net>
** 
** Started on  Thu Mar 26 09:30:54 2015 GENTIER Remi
** Last update Thu Mar 26 12:00:33 2015 GENTIER Remi
*/

char	*my_strcpy(char *dest, char *src)
{
  int	i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      ++i;
    }
  dest[i] = 0;
  return (dest);
}
