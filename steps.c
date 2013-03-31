/*
** steps.c for lemip in /home/dell-a_f//projets/depot/lemipc
** 
** Made by florian dell-aiera
** Login   <dell-a_f@epitech.net>
** 
** Started on  Sun Mar 31 14:08:10 2013 florian dell-aiera
** Last update Sun Mar 31 20:23:29 2013 florian dell-aiera
*/

#include	"lemipc.h"

void		step_one(t_game *game)
{
  game->access++;
  if (count_team(game->addr, '1') > count_team(game->addr, '2'))
    game->team = '2';
  else
    game->team = '1';
  printf("team %c\n", game->team);
}

void		step_two(t_game *game)
{
  game->access++;
  if (game->first == 0)
    game->new = get_pos_depart(game);
  game->addr[game->new] = game->team;
}

static int	check_play(t_game *game)
{
  if (game->play == 1)
    if (count_team(game->addr, '1') <= 1 || count_team(game->addr, '2') <= 1)
      return (-1);
  return (0);
}

int		step_three(t_game *game)
{
  int		ret;

  sleep(1);
  ret = check_play(game);
  if (ret == -1)
    return (-1);
  if (is_quitting(game, game->team, game->new) == 1)
    return (-1);
  else if (game->team != 'o')
    {
      game->addr[game->new] = 'o';
      game->new = get_rand_number(game);
      while (game->addr[game->new] != 'o')
	game->new = get_rand_number(game);
      game->addr[game->new] = game->team;
      return (0);
    }
  else
    return (0);
}
