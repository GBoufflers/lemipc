/*
** check_team.c for check_team in /home/dell-a_f//projets/depot/lemipc
** 
** Made by florian dell-aiera
** Login   <dell-a_f@epitech.net>
** 
** Started on  Fri Mar 29 17:18:28 2013 florian dell-aiera
** Last update Fri Mar 29 19:09:31 2013 florian dell-aiera
*/

#include	"lemipc.h"

int		check_team(t_game *game)
{
  int		nb;

  if (nb = count_team(game->addr, '1') <= 1)
    {
      printf("%d\n", nb);
      printf("team blue win\n");
      return (-1);
    }
  else if (nb = count_team(game->addr, '2') <= 1)
    {
      printf("%d\n", nb);
      printf("team rouge win\n");
      return (-1);
    }
  return (0);
}
