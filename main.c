#include	"lemipc.h"

void		lock(struct sembuf *sops)
{
  sops->sem_num = 0;
  sops->sem_flg = 0;
  sops->sem_op = -1;
}

void		unlock(struct sembuf *sops)
{
  sops->sem_num = 0;
  sops->sem_flg = 0;
  sops->sem_op = 1;
}

int		get_rand_number()
{
  return (rand() % 25);
}

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

int		is_quitting(char *addr, char team, int pos)
{
  return (0);
}

void		first_player(t_game *game)
{
  game->sem_id = semget(game->key, 1, SHM_R | SHM_W | IPC_CREAT);
  game->shm_id = shmget(game->key,  42, IPC_CREAT | SHM_R | SHM_W);
  game->addr = shmat(game->shm_id, NULL, SHM_R | SHM_W);
  sprintf((char *)game->addr, "ooooooooooooooooooooooooo");
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

  access = 0;
  game->addr = shmat(game->shm_id, NULL, SHM_R | SHM_W);
  ret = 0;
  while (1 && ret == 0)
    {
      lock(&(game->sops));
      semctl(game->sem_id, 0, GETVAL);
      semop(game->sem_id, &(game->sops), 1);
      if (access == 0)
	{
	  game->access++;
	  if (count_team(game->addr, '1') > count_team(game->addr, '2'))
	    game->team = '2';
	  else
	    game->team = '1';
	  printf("etape 1 team %c\n", game->team);
	}
      else if (game->access == 1)
	{
	  game->access++;
	  game->new = get_rand_number();
	  while (addr[game->new] != 'o')
	    game->new = get_rand_number();
	  addr[game->new] = game->team;
	  printf("etape 2\n");
	}
      else
	{
	  if (is_quitting(addr, team, new) == 1)
	    ret = -1;
	  else
	    {
	      addr[new] = 'o';
	      new = get_rand_number();
	      while (addr[new] != 'o')
		new = get_rand_number();
	      addr[new] = team;
	      printf("etape 3 position %d\n", new);
	    }
	}
      unlock(&sops);
      semop(sem_id, &sops, 1);
      semctl(sem_id, 0, GETVAL);
      sleep(1);
    }
  shmctl(shm_id, IPC_RMID, NULL);
}

int		main(int ac, char **av)
{
  t_game	*game;

  if (ac != 2)
    {
      printf("Usage : %s pathname\n", av[0]);
      return (-1);
    }
  game = malloc(sizeof(t_game));
  srand(time(NULL));
  game->key = ftok(av[1], 0);
  game->shm_id = shmget(game->key, 42, SHM_R | SHM_W);
  printf("shmId = %d\n", game->shm_id);
  if (game->shm_id == -1)
    first_player(game->key, game->shm_id, game->sem_id);
  else
    others(game->key, game->shm_id, game->sem_id);
  return (0);
}
