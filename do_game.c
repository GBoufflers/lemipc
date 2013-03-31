/*
** do_game.c for do_game in /home/dell-a_f//projets/depot/lemipc
** 
** Made by florian dell-aiera
** Login   <dell-a_f@epitech.net>
** 
** Started on  Sun Mar 31 14:49:03 2013 florian dell-aiera
** Last update Sun Mar 31 15:00:24 2013 florian dell-aiera
*/

#include	"lemipc.h"

void		do_game(t_game *game, int ret, int nb)
{
  while (1 && ret == 0)
    {
      lock(&(game->sops));
      semctl(game->sem_id, 0, GETVAL);
      semop(game->sem_id, &(game->sops), 1);
      if (game->access == 0)
	step_one(game);
      else if (game->access == 1)
	step_two(game);
      else if (game->play == 1)
	ret = step_three(game);
      nb = count_team(game->addr, '1') + count_team(game->addr, '2');
      if (nb >= 4)
	game->play = 1;
      unlock(&(game->sops));
      semop(game->sem_id, &(game->sops), 1);
      semctl(game->sem_id, 0, GETVAL);
    }
}
