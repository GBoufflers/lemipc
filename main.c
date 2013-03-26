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
  return (rand() % 50);
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

int		main(int ac, char **av)
{
  key_t		key;
  int		shm_id;
  int		sem_id;
  char		*addr;
  struct sembuf sops;
  
  if (ac != 2)
    {
      printf("Usage : %s pathname\n", av[0]);
      return (-1);
    }
  srand(time(NULL));
  key = ftok(av[1], 0);
  printf("Key : %d\n", key);
  shm_id = shmget(key, 42, SHM_R | SHM_W);
  printf("shmId = %d\n", shm_id);
  if (shm_id == -1)
    {
      sem_id = semget(key, 1, SHM_R | SHM_W | IPC_CREAT);
      shm_id = shmget(key,  42, IPC_CREAT | SHM_R | SHM_W);
      addr = shmat(shm_id, NULL, SHM_R | SHM_W);
      sprintf((char *)addr, "ooooooooooooooooooooooooooooooooooooooooooooo");
      printf("Created shm segment %d\n", shm_id);
      semctl(sem_id, 0, SETVAL, 1);
      while (1)
	{
	  printf("%s\n", addr);
	  lock(&sops);
	  semctl(sem_id, 0, GETVAL);
	  semop(sem_id, &sops, 1);
	  addr[5] = '1';
	  unlock(&sops);
	  semop(sem_id, &sops, 1);
	  semctl(sem_id, 0, GETVAL);
	  sleep(1);
	}
    }
  else
    {
      char	team;
      int	access;
      int	new;
      int	ret;

      access = 0;
      addr = shmat(shm_id, NULL, SHM_R | SHM_W);
      ret = 0;
      while (1 && ret == 0)
	{
	  lock(&sops);
	  semctl(sem_id, 0, GETVAL);
	  semop(sem_id, &sops, 1);
	  if (access == 0)
	    {
	      access++;
	      if (count_team(addr, '1') > count_team(addr, '2'))
		team = '2';
	      else
		team = '1';
	      printf("etape 1 team %c\n", team);
	    }
	  else if (access == 1)
	    {
	      access++;
	      new = get_rand_number();
	      while (addr[new] != 'o')
		new = get_rand_number();
	      addr[new] = team;
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
  return (0);
}
