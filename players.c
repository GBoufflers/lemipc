/*
** players.c for lemipc in /home/dell-a_f//projets/depot/lemipc
** 
** Made by florian dell-aiera
** Login   <dell-a_f@epitech.net>
** 
** Started on  Sun Mar 31 14:08:04 2013 florian dell-aiera
** Last update Sun Mar 31 15:51:05 2013 florian dell-aiera
*/

#include	"lemipc.h"

int		count_team(char *map, char c)
{
  int		count;
  int		i;

  i = 0;
  count = 0;
  while (map[i] != '\0')
    {
      if (map[i] == c)
	count++;
      i++;
    }
  return (count);
}

static void    	end(t_game *game)
{
  if (game->play == 1)
    {
      if (count_team(game->addr, '1') <= 1)
	{
	  printf("blue win\n");
	  shmctl(game->shm_id, IPC_RMID, NULL);
	}
      if (count_team(game->addr, '2') <= 1)
	{
	  printf("red win\n");
	  shmctl(game->shm_id, IPC_RMID, NULL);
	}
    }
}

void		first_player(t_game *game)
{
  int		ret;
  int		nb;

  ret = 0;
  nb = 0;
  game->sem_id = semget(game->key, 1, SHM_R | SHM_W | IPC_CREAT);
  game->shm_id = shmget(game->key,  52, IPC_CREAT | SHM_R | SHM_W);
  game->addr = shmat(game->shm_id, NULL, SHM_R | SHM_W);
  sprintf((char *)game->addr,
	  "ooooooooooooooooooooooooooooooooooooooooooooooooo");
  printf("Created shm segment %d\n", game->shm_id);
  semctl(game->sem_id, 0, SETVAL, 1);
  do_game(game, ret, nb);
  end(game);
}

void		others(t_game *game)
{
  int		ret;
  int		nb;

  game->access = 0;
  game->addr = shmat(game->shm_id, NULL, SHM_R | SHM_W);
  ret = 0;
  nb = 0;
  check_nb_players(game);
  do_game(game, ret, nb);
  end(game);
}
