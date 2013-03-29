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
  int		max;

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
    }
  printf("pos ==> %d \n", pos);
  return (pos);
}
