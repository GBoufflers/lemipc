#include	"lemipc.h"

int		main(int ac, char **av)
{
  key_t		key;
  int		shm_id;
  int		sem_id;
  void		*addr;
  struct sembuf sops;
  
  if (ac != 2)
    {
      printf("Usage : %s pathname\n", av[0]);
      return (-1);
    }
  key = ftok(av[1], 0);
  printf("Key : %d\n", key);
  shm_id = shmget(key, 42, SHM_R | SHM_W);
  printf("b1\n");
  sem_id = semget(key, 1, SHM_R | SHM_W);
  printf("b2\n");
  if (shm_id == -1)
    {
      printf("b3\n");
      shm_id = shmget(key,  42, IPC_CREAT | SHM_R | SHM_W);
      printf("b4\n");
      addr = shmat(shm_id, NULL, SHM_R | SHM_W);
      printf("b5\n");
      sprintf((char *)addr, "ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo");
      printf("Created shm segment %d\n", shm_id);
      while (1)
	{
	  printf("%s\n", (char *)addr);
	  sops.sem_num = 0;
	  sops.sem_flg = 0;
	  sops.sem_op = -1;
	  semctl(sem_id, 0, GETVAL);
	  semop(sem_id, &sops, 1);
	  sprintf((char *)addr, "1oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo");
	  sops.sem_num = 0;
	  sops.sem_flg = 0;
	  sops.sem_op = 1;
	  semop(sem_id, &sops, 1);
	  semctl(sem_id, 0, GETVAL);
	  sleep(1);
	}
    }
  else
    {
      while (1)
	{
	  printf("bonjour !!\n");
	  sops.sem_num = 0;
	  sops.sem_flg = 0;
	  sops.sem_op = -1;
	  printf("bonjour 2!!\n");
	  semctl(sem_id, 0, GETVAL);
	  printf("bonjour 3!!\n");
	  semop(sem_id, &sops, 1);
	  printf("bonjour 4!!\n");
	  sprintf((char *)addr, "2oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo");
	  printf("bonjour 5!!\n");
	  sops.sem_num = 0;
	  sops.sem_flg = 0;
	  sops.sem_op = 1;
	  semop(sem_id, &sops, 1);
	  semctl(sem_id, 0, GETVAL);
	  sleep(1);
	}
      shmctl(shm_id, IPC_RMID, NULL);
    }
  return (0);
}
