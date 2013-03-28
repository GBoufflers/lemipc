#include	"lemipc.h"


void		step_one(t_game *game)
{
  game->access++;
  if (count_team(game->addr, '1') > count_team(game->addr, '2'))
    game->team = '2';
  else
    game->team = '1';
  printf("etape 1 team %c\n", game->team);
}

void		step_two(t_game *game)
{
  game->access++;
  game->new = get_rand_number();
  while (game->addr[game->new] != 'o')
    game->new = get_rand_number();
  game->addr[game->new] = game->team;
  printf("etape 2\n");
}

void		step_three(t_game *game)
{
  int		ret;

  if (is_quitting(game->addr, game->team, game->new) == 1)
    ret = -1;
  else
    {
      game->addr[game->new] = 'o';
      game->new = get_rand_number();
      while (game->addr[game->new] != 'o')
	game->new = get_rand_number();
      game->addr[game->new] = game->team;
      printf("etape 3 position %d\n", game->new);
    }
}
