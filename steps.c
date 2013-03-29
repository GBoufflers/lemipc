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
  if (game->first == 0)
    game->new = get_pos_depart(game);
  game->addr[game->new] = game->team;
  printf("etape 2\n");
}

int		step_three(t_game *game)
{
  printf("etape 3\n");
  if (is_quitting(game, game->team, game->new) == 1)
    {
      
      /* if (count_team(game->addr, '1')  <= 1) */
      /* 	return (-1); */
      /* if (count_team(game->addr, '2')  <= 1) */
      /* 	return (-1);  */
      printf("leaving\n");
      return (0);
    }
  else if (game->team != 'o')
    {
      game->addr[game->new] = 'o';
      game->new = get_rand_number(game);
      while (game->addr[game->new] != 'o')
	game->new = get_rand_number(game);
      game->addr[game->new] = game->team;
      return (0);
    }
}
