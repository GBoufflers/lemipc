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

void		first_player(t_game *game)
{
  game->sem_id = semget(game->key, 1, SHM_R | SHM_W | IPC_CREAT);
  game->shm_id = shmget(game->key,  52, IPC_CREAT | SHM_R | SHM_W);
  game->addr = shmat(game->shm_id, NULL, SHM_R | SHM_W);
  sprintf((char *)game->addr, "ooooooooooooooooooooooooooooooooooooooooooooooooo");
  printf("Created shm segment %d\n", game->shm_id);
  semctl(game->sem_id, 0, SETVAL, 1);
  while (1)
    {
      printf("%s\n", game->addr);
      lock(&(game->sops));
      semctl(game->sem_id, 0, GETVAL);
      semop(game->sem_id, &(game->sops), 1);
      game->addr[5] = '1';
      unlock(&(game->sops));
      semop(game->sem_id, &(game->sops), 1);
      semctl(game->sem_id, 0, GETVAL);
      sleep(1);
    }
}

void		others(t_game *game)
{
  int		ret;

  game->access = 0;
  game->addr = shmat(game->shm_id, NULL, SHM_R | SHM_W);
  ret = 0;
  while (1 && ret == 0)
    {
      lock(&(game->sops));
      semctl(game->sem_id, 0, GETVAL);
      semop(game->sem_id, &(game->sops), 1);
      if (game->access == 0)
	step_one(game);
      else if (game->access == 1)
	step_two(game);
      else
	ret = step_three(game);
      unlock(&game->sops);
      semop(game->sem_id, &game->sops, 1);
      semctl(game->sem_id, 0, GETVAL);
      sleep(1);
    }
  shmctl(game->shm_id, IPC_RMID, NULL);
}
