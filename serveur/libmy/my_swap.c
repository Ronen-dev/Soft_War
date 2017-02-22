/*
** my_swap.c for my_swap in /home/gentie_r/SVN-depots/piscine_c_Jour03/gentie_r/my_swap
** 
** Made by GENTIER Remi
** Login   <Gentie_r@etna-alternance.net>
** 
** Started on  Wed Mar 25 10:36:03 2015 GENTIER Remi
** Last update Wed Mar 25 10:44:55 2015 GENTIER Remi
*/

void	my_swap(int *a, int *b)
{
  int tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;
}
