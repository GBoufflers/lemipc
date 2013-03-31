/*
** main.c for lemipc in /home/dell-a_f//projets/depot/lemipc
** 
** Made by florian dell-aiera
** Login   <dell-a_f@epitech.net>
** 
** Started on  Sun Mar 31 14:07:56 2013 florian dell-aiera
** Last update Sun Mar 31 14:07:57 2013 florian dell-aiera
*/

#include	"lemipc.h"

int		main(int ac, char **av)
{
  t_game	*game;

  if (ac != 2)
    {
      printf("Usage : %s pathname\n", av[0]);
      return (-1);
    }
  game = xmalloc(sizeof(t_game));
  srand(time(NULL));
  game->key = ftok(av[1], 0);
  game->shm_id = shmget(game->key, 52, SHM_R | SHM_W);
  printf("shmId = %d\n", game->shm_id);
  game->first = 0;
  if (game->shm_id == -1)
    first_player(game);
  else
    others(game);
  return (0);
}
