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
  key = ftok(av[1], 0);
  printf("Key : %d\n", key);
  shm_id = shmget(key, 42, SHM_R | SHM_W);
  printf("shmId = %d\n", shm_id);
  if (shm_id == -1)
    {
      sem_id = semget(key, 1, SHM_R | SHM_W | IPC_CREAT);
      shm_id = shmget(key,  42, IPC_CREAT | SHM_R | SHM_W);
      addr = shmat(shm_id, NULL, SHM_R | SHM_W);
      sprintf((char *)addr, "ooooooooo\nooooooooo\nooooooooo\nooooooooo\nooooooooo\n");
      printf("Created shm segment %d\n", shm_id);
      semctl(sem_id, 0, SETVAL, 1);
      printf("%s\n", addr);
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
      addr = shmat(shm_id, NULL, SHM_R | SHM_W);
      while (1)
	{
	  lock(&sops);
	  semctl(sem_id, 0, GETVAL);
	  semop(sem_id, &sops, 1);
	  addr[15] = '2';
	  unlock(&sops);
	  semop(sem_id, &sops, 1);
	  semctl(sem_id, 0, GETVAL);
	  sleep(1);
	}
      shmctl(shm_id, IPC_RMID, NULL);
    }
  return (0);
}
