/*
** my_strncpy.c for  in /home/gentie_r/SVN-depots/piscine_c_Jour04/gentie_r/my_strncpy
** 
** Made by GENTIER Remi
** Login   <Gentie_r@etna-alternance.net>
** 
** Started on  Thu Mar 26 09:34:19 2015 GENTIER Remi
** Last update Mon Mar 30 10:27:17 2015 GENTIER Remi
*/

char	*my_strncpy(char *dest, char *src, int n)
{
  int i = 0;

  while (src[i] && i < n)
    {
      dest[i] = src[i];
      ++i;
    }
  if (!dest[i])
    dest[i] = 0;
  return (dest);
}
