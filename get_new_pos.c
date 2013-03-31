/*
** get_new_pos.c for lempic in /home/dell-a_f//projets/depot/lemipc
** 
** Made by florian dell-aiera
** Login   <dell-a_f@epitech.net>
** 
** Started on  Sun Mar 31 14:07:28 2013 florian dell-aiera
** Last update Sun Mar 31 14:53:22 2013 florian dell-aiera
*/

#include	"lemipc.h"

int		get_pos_depart(t_game *game)
{
  int		pos;

  game->first++;
  pos = rand() % 49;
  while (game->addr[pos] != 'o')
    pos = rand() % 49;
  return (pos);
}

int		get_rand_number(t_game *game)
{
  int		nb;
  int		pos;

  nb = rand() % 4;
  pos = game->new;
  while (pos == game->new)
    {
      if (nb == 0 && pos < 48)
	pos += 1;
      if (nb == 1 && pos < 41)
	pos += 7;
      if (nb == 2 && pos > 0)
	pos -= 1;
      if (nb == 3 && pos > 6)
	pos -= 7;
      nb = rand() % 4;
    }
  return (pos);
}
