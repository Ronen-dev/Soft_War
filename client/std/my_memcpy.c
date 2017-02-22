/*
** my_memcpy.c for  in /home/instaa/client/coskun_a/std
** 
** Made by COSKUN Antoine
** Login   <coskun_a@etna-alternance.net>
** 
** Started on  Wed Jun 17 11:29:19 2015 COSKUN Antoine
** Last update Wed Jun 17 12:11:28 2015 COSKUN Antoine
*/

void			my_memcpy(void *dest, void *src, int size)
{
  char			*ptr_dest;
  char			*ptr_src;
  int			i;

  i = 0;
  ptr_dest = (char *)dest;
  ptr_src = (char *)src;
  while (i < size)
    {
      ptr_dest[i] = ptr_src[i];
      i++;
    }
}
