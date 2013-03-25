#include	"lemipc.h"

int		main(int ac, char **av)
{
  key_t		key;
  int		shm_id;

  if (ac != 2)
    {
      printf("Usage : %s pathname\n", av[0]);
      return (-1);
    }
  key = ftok(av[1], 0);
  printf("Key : %d\n", key);
  shm_id = shmget(key, 42, SHM_R | SHM_W);
  if (shm_id == -1)
    {
      shm_id = shmget(key,  42, IPC_CREAT | SHM_R | SHM_W);
      printf("Created shm segment %d\n", shm_id);
    }
  else
    {
      printf("Using shm segment %d\n", shm_id);
      shmctl(shm_id, IPC_RMID, NULL);
    }
  return (0);
}
