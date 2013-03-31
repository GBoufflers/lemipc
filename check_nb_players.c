/*
** check_nb_players.c for check in /home/dell-a_f//projets/depot/lemipc
** 
** Made by florian dell-aiera
** Login   <dell-a_f@epitech.net>
** 
** Started on  Sun Mar 31 13:36:46 2013 florian dell-aiera
** Last update Sun Mar 31 13:55:27 2013 florian dell-aiera
*/

#include	"lemipc.h"

void		check_nb_players(t_game *game)
{
  int		nb;

  nb = count_team(game->addr, '1') + count_team(game->addr, '2');
  if (nb >= 12)
    {
      printf("Too many players sorry\n");
      exit(0);
    }
}
