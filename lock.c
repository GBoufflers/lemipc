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
